#define CMD_TAG 0x01
#define CMD_UNTAG 0x02
#define CMD_FILES 0x04
#define CMD_TAGS 0x08
#define CMD_MV 0x10
#define CMD_CP 0x20
#define CMD_RM 0x40
#define CMD_ALL 0x7f

enum error_codes {
    NO_ERR = 0,          /* nothing was wrong */
    ERR_CWD_NOT_FOUND,   /* couldn't get current working directory, bailing */
    ERR_WRONG_NUM_ARGS,  /* wrong number of arguments to a command */
    ERR_BAD_CMD          /* no such command */
};

void print_usage (char*, int);
int tag (char*, int, char* []);
int untag (char*, int, char* []);
int files (char*);
int tags (char*);
int tagged_mv (int, char* [], char*);
int tagged_cp (int, char* [], char*);
int tagged_rm (int, char* []);
int reindex (char*);
void prepare_dir_structure (char*);
char* tigger_data_path (char*);
