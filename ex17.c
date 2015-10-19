#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h> // what do we use from this?
#include <string.h>

struct Address {
        int id;
        int set;
        char *name; // pointer to string of unknown size
        char *email; // pointer to string of unknown size
};

struct Database {
        struct Address *addresses; // rows is a pointer to an array of Address structs of unknown size
        size_t max_rows; // the max number of rows
        size_t max_str_len; // the max chars in a string
};

struct Connection {
        FILE *file;
        struct Database *db;
};

void Database_close(struct Connection *conn)
{
        if (conn) {
                if (conn->file)
                        fclose(conn->file);
                if (conn->db) {
                    if (conn->db->addresses) {
                        struct Address *address_ptr = conn->db->addresses;
                        for (int i = 0; i < conn->db->max_rows; ++i) {
                            free(address_ptr->name);
                            free(address_ptr->email);
                            ++address_ptr;
                        }

                        free(conn->db->addresses);
                    }
                    free(conn->db);
                }
                free(conn);
        }
}

void die(const char *message, struct Connection *conn)
{
        if (errno) {
                perror(message);
        } else {
                printf("ERROR: %s\n", message);
        }

        if (conn)
                Database_close(conn);

        exit(1);
}

void Address_print(struct Address *addr)
{
        printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
        fread(&conn->db->max_rows, sizeof(size_t), 1, conn->file);
        fread(&conn->db->max_str_len, sizeof(size_t), 1, conn->file);

        int row_count = conn->db->max_rows;
        int strlen = conn->db->max_str_len;

        struct Address *address = malloc(sizeof(struct Address) * row_count);
        conn->db->addresses = address;

        for (int i = 0; i < conn->db->max_rows; ++i) {
            address->name = calloc(strlen, sizeof(char));
            address->email = calloc(strlen, sizeof(char));

            fread(&address->id, sizeof(int), 1, conn->file);
            fread(&address->set, sizeof(int), 1, conn->file);
            fread(address->name, sizeof(char), strlen, conn->file);
            fread(address->email, sizeof(char), strlen, conn->file);
            ++address;
        }


        // if (db_count != 1)
        //         die("Failed to load database.", conn);
}

struct Connection *Database_open(const char *filename, char mode)
{
        struct Connection *conn = malloc(sizeof(struct Connection));
        if (!conn)
                die("Memory error", conn);

        conn->db = malloc(sizeof(struct Database));
        if (!conn->db)
                die("Memory error", conn);

        if (mode == 'c') {
                conn->file = fopen(filename, "w+");
        } else {
                conn->file = fopen(filename, "r+");

                if (conn->file){
                        Database_load(conn);
                }
        }

        if (!conn->file)
                die("Failed to open the file", conn);

        return conn;
}

void Database_write(struct Connection *conn)
{
        rewind(conn->file);

        // THIS IS TERRIBLE - better to write to plaintext/JSON
        fwrite(&conn->db->max_rows, sizeof(size_t), 1, conn->file);
        fwrite(&conn->db->max_str_len, sizeof(size_t), 1, conn->file);

        struct Address *address = conn->db->addresses;

        size_t max_str_len = conn->db->max_str_len;

        for (int i = 0; i < conn->db->max_rows; ++i) {
            fwrite(&address->id, sizeof(int), 1, conn->file);
            fwrite(&address->set, sizeof(int), 1, conn->file);
            fwrite(address->name, sizeof(char), max_str_len, conn->file);
            fwrite(address->email, sizeof(char), max_str_len, conn->file);
            address++;
        }

        // if (db_count != 1)
        //         die("Failed to write database.", conn);

        int rc = fflush(conn->file);
        if (rc == -1)
                die("Cannot flush database.", conn);
}

void Database_create(struct Connection *conn, size_t max_rows, size_t max_str_len)
{
        conn->db->addresses = malloc(sizeof(struct Address) * max_rows);
        conn->db->max_rows = max_rows;
        conn->db->max_str_len = max_str_len;

        for (int i = 0; i < max_rows; ++i) {
            // make a prototype to initialize it
            struct Address addr = {
                .id = i,
                .set = 0
            };
            addr.name = calloc(max_str_len, sizeof(char));
            addr.email = calloc(max_str_len, sizeof(char));
            // then just assign it
            conn->db->addresses[i] = addr;
        }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
        struct Address *addr = &conn->db->addresses[id]; // == &(conn->db->rows[id])
        if (addr->set)
                die("Already set, delete it first.", conn);

        addr->set = 1;
        char *res = strncpy(addr->name, name, conn->db->max_str_len); // WARNING: if the buffer fills, strncpy will NOT null-terminate it!
        res[conn->db->max_str_len] = '\0'; // always force the final null to terminate the string
        if (!res)
                die("Name copy failed", conn);

        res = strncpy(addr->email, email, conn->db->max_str_len);
        if (!res)
                die("Email copy failed", conn);
}

void Database_get(struct Connection *conn, int id)
{
        struct Address *addr = &conn->db->addresses[id]; // == &(conn->db->rows[id])

        if (addr->set) { // NULL pointer evaluates to false
                Address_print(addr);
        } else {
                die("ID is not set", conn);
        }
}

void Database_delete(struct Connection *conn, int id)
{
        struct Address addr = {.id = id, .set = 0}; // shorthand for initializing a struct
        conn->db->addresses[id] = addr; // copy this temporary struct to this location
}

void Database_list(struct Connection *conn)
{
        struct Database *db = conn->db;
        size_t max_rows = db->max_rows;

        for (int i = 0; i < max_rows; ++i) {
                struct Address *cur = &db->addresses[i];

                if (cur->set)
                        Address_print(cur);
        }
}

void id_in_bounds(int id, struct Connection *conn)
{
        if (id >= conn->db->max_rows)
                die("There's not that many records.", conn);
}
int main(int argc, char *argv[])
{
        if (argc < 3)
                die("USAGE: ex17 <dbfile> <action> [action params]", NULL);

        char *filename = argv[1];
        char action = argv[2][0];
        struct Connection *conn = Database_open(filename, action);
        int id = 0;

        switch(action) {
                case 'c':
                        if (argc != 5)
                                die("Need row_count, max_string_length to create", conn);
                        size_t max_rows = (size_t) (atoi(argv[3]));
                        size_t max_str_len = (size_t) (atoi(argv[4]));
                        Database_create(conn, max_rows, max_str_len);
                        Database_write(conn);
                        break;
                case 'g':
                        id = atoi(argv[3]);
                        id_in_bounds(id, conn);
                        if (argc != 4)
                                die("Need an id to get", conn);
                        Database_get(conn, id);
                        break;
                case 's':
                        id = atoi(argv[3]);
                        id_in_bounds(id, conn);
                        if (argc != 6)
                                die("Need id, name, email to set", conn);
                        Database_set(conn, id, argv[4], argv[5]);
                        Database_write(conn);
                        break;
                case 'd':
                        id = atoi(argv[3]);
                        id_in_bounds(id, conn);
                        if (argc != 4)
                                die("Need id to delete", conn);

                        Database_delete(conn, id);
                        Database_write(conn);
                        break;
                case 'l':
                        Database_list(conn);
                        break;
                default:
                        die("Invalid action, only: c=create, g=get, s=set, d=del, l=list", conn);
        }

        Database_close(conn);

        return 0;
}
