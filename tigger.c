#include <string.h>
#include <stdio.h>

#define CMD_TAG 0x01
#define CMD_UNTAG 0x02
#define CMD_FILES 0x04
#define CMD_TAGS 0x08
#define CMD_MV 0x10
#define CMD_CP 0x20
#define CMD_RM 0x40
#define CMD_ALL 0x7f

void print_usage (char*, int);


int main (int argc, char* argv []) {
    if (argc == 1) {
        print_usage(argv[0], CMD_ALL);
        return 0;
    }

    if (!strcmp("tag", argv[1])) {
        if (argc < 4) {
            printf("tag: too few arguments\n\n");
            print_usage(argv[0], CMD_TAG);
            return 1;
        }
        printf("tag()\n");
    } else if (!strcmp("untag", argv[1])) {
        if (argc < 4) {
            printf("untag: too few arguments\n\n");
            print_usage(argv[0], CMD_UNTAG);
            return 1;
        }
        printf("untag()\n");
    } else if (!strcmp("files", argv[1])) {
        if (argc != 3) {
            printf("files: wrong number of arguments\n\n");
            print_usage(argv[0], CMD_FILES);
            return 1;
        }
        printf("files()\n");
    } else if (!strcmp("tags", argv[1])) {
        if (argc != 3) {
            printf("tags: wrong number of arguments\n\n");
            print_usage(argv[0], CMD_TAGS);
            return 1;
        }
        printf("tags()\n");
    } else if (!strcmp("mv", argv[1])) {
        if (argc < 4) {
            printf("mv: too few arguments\n\n");
            print_usage(argv[0], CMD_MV);
            return 1;
        }
        printf("mv()\n");
    } else if (!strcmp("cp", argv[1])) {
        if (argc < 4) {
            printf("cp: too few arguments\n\n");
            print_usage(argv[0], CMD_CP);
            return 1;
        }
        printf("cp()\n");
    } else if (!strcmp("rm", argv[1])) {
        if (argc < 3) {
            printf("rm: too few arguments\n\n");
            print_usage(argv[0], CMD_RM);
            return 1;
        }
        printf("rm()\n");
    } else {
        printf("%s: unrecognized command\n\n", argv[1]);
        print_usage(argv[0], CMD_ALL);
        return 1;
    }

    return 0;
}

void print_usage (char* cmd_name, int cmds_mask) {
    if (cmds_mask == CMD_ALL) {
        printf("Usage: %s [COMMAND [OPTIONS]]\n\n", cmd_name);

        printf("Commands:");
    } else {
        printf("Usage:");
    }

    if (cmds_mask & CMD_TAG) {
        printf("\n\ttag FILE TAG [TAG ..]\n");
        printf("\t\tAdds all TAGs to FILE's tag list.\n");
    }

    if (cmds_mask & CMD_UNTAG) {
        printf("\n\tuntag FILE TAG [TAG ..]\n");
        printf("\t\tRemoves all TAGs from FILE's tag list.\n");
    }

    if (cmds_mask & CMD_FILES) {
        printf("\n\tfiles TAG\n");
        printf("\t\tLists all files with tag TAG.\n");
    }

    if (cmds_mask & CMD_TAGS) {
        printf("\n\ttags FILE\n");
        printf("\t\tLists all of FILE's tags.\n");
    }

    if (cmds_mask & CMD_MV) {
        printf("\n\tmv FILE [FILE ..] TARGET\n");
        printf("\t\tMove one or more FILEs to TARGET, renaming if only one FILE is given and TARGET is not a directory. Update tag lists to reflect the change(s).\n");
    }

    if (cmds_mask & CMD_CP) {
        printf("\n\tcp FILE [FILE ..] TARGET\n");
        printf("\t\tCopy one or more FILEs to TARGET, copying to a new filename if only one FILE is given and TARGET is not a directory. Update tag lists to reflect the change(s).\n");
    }

    if (cmds_mask & CMD_RM) {
        printf("\n\trm FILE [FILE ..]\n");
        printf("\t\tRemove all FILEs. Update tag lists to reflect the change(s).\n");
    }
}
