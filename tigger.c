#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "tigger.h"


int main (int argc, char* argv []) {
    if (argc == 1) {
        print_usage(argv[0], CMD_ALL);
        return NO_ERR;
    }

    if (!strcmp("tag", argv[1])) {
        if (argc < 4) {
            printf("tag: too few arguments\n\n");
            print_usage(argv[0], CMD_TAG);
            return ERR_WRONG_NUM_ARGS;
        }
        return tag(argv[2], argc-3, argv+3);
    } else if (!strcmp("untag", argv[1])) {
        if (argc < 4) {
            printf("untag: too few arguments\n\n");
            print_usage(argv[0], CMD_UNTAG);
            return ERR_WRONG_NUM_ARGS;
        }
        return untag(argv[2], argc-3, argv+3);
    } else if (!strcmp("files", argv[1])) {
        if (argc != 3) {
            printf("files: wrong number of arguments\n\n");
            print_usage(argv[0], CMD_FILES);
            return ERR_WRONG_NUM_ARGS;
        }
        return files(argv[2]);
    } else if (!strcmp("tags", argv[1])) {
        if (argc != 3) {
            printf("tags: wrong number of arguments\n\n");
            print_usage(argv[0], CMD_TAGS);
            return ERR_WRONG_NUM_ARGS;
        }
        return tags(argv[2]);
    } else if (!strcmp("mv", argv[1])) {
        if (argc < 4) {
            printf("mv: too few arguments\n\n");
            print_usage(argv[0], CMD_MV);
            return ERR_WRONG_NUM_ARGS;
        }
        return tagged_mv(argc-3, argv+2, argv[argc-1]);
    } else if (!strcmp("cp", argv[1])) {
        if (argc < 4) {
            printf("cp: too few arguments\n\n");
            print_usage(argv[0], CMD_CP);
            return ERR_WRONG_NUM_ARGS;
        }
        return tagged_mv(argc-3, argv+2, argv[argc-1]);
    } else if (!strcmp("rm", argv[1])) {
        if (argc < 3) {
            printf("rm: too few arguments\n\n");
            print_usage(argv[0], CMD_RM);
            return ERR_WRONG_NUM_ARGS;
        }
        return tagged_rm(argc-2, argv+2);
    } else {
        printf("%s: unrecognized command\n\n", argv[1]);
        print_usage(argv[0], CMD_ALL);
        return ERR_BAD_CMD;
    }
}


int tag (char* target_fname, int tag_count, char* tag_list[])
{
    char working_dir[FILENAME_MAX];

    if (!(getcwd(working_dir, sizeof(working_dir)))) {
        printf("Couldn't get current working directory, bailing out!\n");
        return ERR_CWD_NOT_FOUND;
    }

    reindex(working_dir);

    return NO_ERR;
}


int untag (char* target_fname, int tag_count, char* tag_list[])
{
    return NO_ERR;
}


int files (char* tag_name)
{
    return NO_ERR;
}


int tags (char* filename)
{
    return NO_ERR;
}


int tagged_mv (int fname_count, char* fname_list[], char* target_loc)
{
    return NO_ERR;
}


int tagged_cp (int fname_count, char* fname_list[], char* target_loc)
{
    return NO_ERR;
}


int tagged_rm (int fname_count, char* fname_list[])
{
    return NO_ERR;
}


int reindex (char* target_dir)
{
    int new_index = 0;

    printf("%s", target_dir);

    return NO_ERR;
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
