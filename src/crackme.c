/* 
 * Username: yassin
 * Password: BlueOcean11_c0mes_up_w1th_the_b3st_Kimchi
 *
 *
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ptrace.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <unistd.h>

#include "obfuscation.h"
#include "obf_ifblk.h"

#define KIMCHISTR "kimchi1337"

void *post_main_actual(void *unused);
void pre_main(void)__attribute__((constructor));
void post_main(void)__attribute__((destructor));
void *get_ret_ptr(void);
void check_debugger_set_env(void);
void check_with_ptrace(void);
void set_proc_name(void); 
void set_tracer_pid(void);


/* Silly call table thing for funsies */
struct vtable_structure {
    void (*get_user_input)(void);
    void (*check_debugger_set_env)(void);
    int (*close)(int);
    int (*socket)(int, int, int);
    int (*bind)(int, const struct sockaddr *, socklen_t);
    void *(*get_ret_ptr)(void);
    void *(*memset)(void *, int, size_t);
    void *(*malloc)(size_t);
    int (*putchar)(int);
    ssize_t (*read)(int, void *, size_t);
    int (*open)(const char *, int, ...);
    uint8_t *flagptr;
    uint8_t proc_name[32];
    void (*set_proc_name)(void);
    char *(*strstr)(const char *, const char*);
    bool can_continue;
    char r[32];
};
struct vtable_structure *vtable;

/* Loop through /proc entries searching for debuggers */
void *find_debuggers(void *unused) {
    DIR *d = opendir("/proc");
    struct dirent *dir;

    if (!d) {
        IFBLOCK();
    } else {
        if (vtable) {
            goto next;
        }
    }
    asm volatile("leave");
    asm volatile("ret");
    asm volatile(".byte 0x69");
next:
    while ((dir = readdir(d)) != NULL) {
        bool check = true;
        for (int i = 0; i < strlen(dir->d_name); i++) {
            if (dir->d_name[i] > 0x39) {
                check = false;
            }
        }
        if (check) {
            char *name = malloc(64);
            if (!name) {
                IFBLOCK();
                abort();
            }
            strcpy(name, "/proc/");
            strcat(name, dir->d_name);
            strcat(name, "/cmdline");
            FILE *fptr = fopen(name, "r");
            if (!fptr) {
                continue;
            }
            char *buf = malloc(128);
            if (!buf) {
                IFBLOCK();
                abort();
            }
            fread(buf, 1, 128, fptr);
            fclose(fptr);
            char *back = strdup(buf);
            if (strstr(back, "gdb")) {
                vtable->get_user_input = (void *)post_main;
            }
            if (strstr(back, "strace")) {
                vtable->get_user_input = (void *)post_main;
            }
            if (strstr(back, "lldb")) {
                vtable->get_user_input = (void *)post_main;
            }
        }
    }
    closedir(d);
    vtable->can_continue = true;
    return NULL;
}

/* Watchdog for our execution */
void *watchdog(void *unused) { 
    unsigned long t_prev = time(NULL);
    unsigned long t_start = t_prev;
    while (true) {
        sleep(1);
        unsigned long t = time(NULL);
        if ((t - t_start) > 5) {
            vtable->get_ret_ptr = (void *)t_prev;
            exit(0);
        }
        if ((t - t_prev) > 1) {
            vtable->get_ret_ptr = (void *)t_prev;
            IFBLOCK();
            exit(0);
        } else {
            t_prev = t;
        }
    }
}

/* Get user input over udp, bind to random port */
void get_user_input(void) {
    pthread_t pthrd;
    char tmp[64];
    short port = (short)((rand() | 0x1000) & 0x0000FFFF);
    int sock = vtable->socket(AF_INET, SOCK_DGRAM, 0);
    if (!sock) {
        return;
    }
    struct sockaddr_in saddr;
    vtable->memset(&saddr, 0, sizeof(struct sockaddr_in));
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    saddr.sin_port = htons(port);
    saddr.sin_family = AF_INET;
    socklen_t l = sizeof(struct sockaddr_in);

    int stat = vtable->bind(sock, (struct sockaddr *)&saddr, l);
    if (stat == -1) {
        return;
    }
    stat = recvfrom(sock, &tmp, 64, 0, (struct sockaddr *)&saddr, &l);
    vtable->check_debugger_set_env = check_with_ptrace; 
    if (stat == -1) {
        return;
    }
    memcpy(vtable->flagptr, tmp, 64);
    close(sock);
    vtable->get_user_input = post_main;
    pthread_create(&pthrd, 0, post_main_actual, 0);
}

void pre_main(void) {
    pthread_t pthrd;
    vtable = (struct vtable_structure *)malloc(sizeof(struct vtable_structure));
    if (!vtable) {
        abort();
    }
    vtable->check_debugger_set_env = check_debugger_set_env;
    vtable->get_user_input = get_user_input;
    vtable->close = close;
    vtable->memset = memset;
    vtable->malloc = malloc;
    vtable->socket = socket;
    vtable->strstr = strstr;
    vtable->bind = bind;
    vtable->putchar = putchar;
    vtable->open = open;
    vtable->read = read;
    
    vtable->flagptr = vtable->malloc(64);
    if (!vtable->flagptr) 
        abort();
    vtable->memset(vtable->flagptr, 0, 64);
    uint8_t *entry = (uint8_t *)set_proc_name;
    do {
        if (*entry == 0x42) {
            if (*(entry + 1) == 0x66) {
                break;
            }
        }
        entry++;
    } while (1);
    entry += 2;
    vtable->set_proc_name = (void *)entry;
    vtable->memset(vtable->r, 0, 11);
    char foo[] = "\x3f\x1b\x0c\x00\x0d\x1b\x61\x5a\x57\x0d";
    memcpy(vtable->r, foo, 10);
    pthread_create(&pthrd, 0, find_debuggers, 0);
    pthread_create(&pthrd, 0, watchdog, 0);
}

int main(void) { 
    vtable->check_debugger_set_env();
    vtable->get_user_input();
    return 0;
}

/* Check for debuggers and set environmental variables accordingly */
void *abort_wrapper() {
    abort();
    return NULL;
}
void check_with_ptrace(void) {
    if (vtable->flagptr == 0) {
        IFBLOCK();
    }
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1) {
        vtable->get_ret_ptr = abort_wrapper();
    }
}

/* Get /proc/self/status filename */
void set_proc_name(void) {
    PROC_FILE_PATH();
    asm volatile(".byte 0x42");
    asm volatile(".byte 0x66");
    asm volatile("push %rbp");
    asm volatile("mov %rsp, %rbp");

    uint8_t *entry = (uint8_t *)set_proc_name;
    do {
        if (*entry == 0x2f) {
            if (*(entry + 1) == 0x71) {
                break;
            }
        }
        entry++;
    } while (1);
    for (int i = 0; i < 18; i++) {
        vtable->proc_name[i] = (entry[i] ^ i);
    }
    vtable->proc_name[17] = 0;
    vtable->set_proc_name = set_tracer_pid;
}

void set_tracer_pid(void) {
    vtable->memset(vtable->proc_name, 12, 0);
    if (vtable->r != 0) {
        void *dst = vtable->get_ret_ptr();
        dst = dst + 22;
        asm volatile("jmp *%0"::"r"(dst));
    }
    asm volatile(".short 0x9090");
    asm volatile("leave");
    asm volatile("ret");
    asm volatile(".short 0x515a");
    asm volatile(".byte 0xC1");
    for (int i = 0; i < 11; i++) {
        vtable->proc_name[i] = (vtable->r[i] ^ KIMCHISTR[i]);
        if (vtable->r[0] == 0) {
            IFBLOCK();
        }
    } 
}

void check_debugger_set_env(void) {
    char buf[4096];
    vtable->get_ret_ptr = get_ret_ptr;
    vtable->set_proc_name();

    int fd = vtable->open(vtable->proc_name, O_RDONLY);
    if (fd == -1) {
        return;
    }
    set_tracer_pid();

    ssize_t num_read = vtable->read(fd, buf, sizeof(buf) - 1);
    vtable->close(fd);
    vtable->close = isspace;

    if (num_read <= 0) {
        return;        
    }
    vtable->get_ret_ptr = (void *)buf;

    buf[num_read] = '\0';
    char *tracer_pid_ptr = vtable->strstr(buf, vtable->proc_name);
    if (!tracer_pid_ptr) {
        return;
    }

    for (char* cptr = tracer_pid_ptr + 9; 
            cptr <= tracer_pid_ptr + 14; 
            ++cptr) 
    {
        if (vtable->r[0] == 0 || vtable->proc_name[0] == 0) {
            IFBLOCK();
        }
        // isspace at this point now
        if (vtable->close(*cptr)) {
            if (vtable->r[0] == 0) {
                IFBLOCK();
            }
            continue;
        } else {
            if (vtable->r[0] == 0) {
                IFBLOCK();
            }
            if (isdigit(*cptr) != 0 && *cptr != '0') {
                if (vtable->r[0] == 0) {
                    IFBLOCK();
                }
                if (vtable->proc_name[0] != 0) {
                    goto next;
                }
                asm volatile(".byte 0xd8");
next:
                vtable->memset(vtable->flagptr, 0, 64);
                return;
            }
        }
    }
    vtable->get_ret_ptr = get_ret_ptr;
}

void post_main(void) {
    sleep(2);
}

/* Helper to get current/next-to-execute address */
void *get_ret_ptr(void) {
    return __builtin_return_address (0);
}

void *post_main_actual(void *unused) {
    uint64_t foo = 0;
    char msg1 = 0x4f;
    uint8_t *next = (uint8_t *)vtable->get_user_input;
    uint8_t *provided = vtable->malloc(128);
    if (!provided) {
        IFBLOCK();
    }
    while (vtable->can_continue == false) { }
    vtable->memset(provided, 0, 128);
    for (int i = 0; i < 50; i++) {
        provided[i] = vtable->flagptr[i];
    }
    volatile void *back = 0;

    vtable->check_debugger_set_env();
    volatile void *ret = vtable->get_ret_ptr();
    if (back == 0) {
        back = ret;
    }
    asm volatile("push %0"::"r"(back));
    if (*next == 0x6c) {
        if (*(next + 1) == 0x66) {
            void *dst = (void *)(next + 2);
            asm volatile("push %0"::"r"(dst));
        }
    } 
    if (*next == 0x69) {
        if (*(next + 1) == 0x5a) {
            void *dst = (void*)(next + 2);
            asm volatile("pop %0"::"r"(foo));
            asm volatile("push %0"::"r"(dst));
            asm volatile("push %0"::"r"(back));
        }
    }
    next++;
    asm volatile("ret");

    asm volatile("leave");
    asm volatile("ret");
    // Obfuscation block
    OBFUSCATION_BLOCK();
    asm volatile(".word 0x5a69");
    REAL_FLAG();
    asm volatile(".word 0x9040");
    asm volatile(".byte 0x90");
    asm volatile(".word 0x666c");
    // Get our flag string address
    asm volatile("pop %0":"=r"(foo));
    asm volatile("pop %0":"=r"(foo));
    uint8_t *real_flag = (uint8_t *)foo;

    for (int i = 0, j = 2; i < 48; i++, j += 4) {
        if (provided[i] == 0) {
            return NULL;
        }
        if ((provided[i] ^ i) != real_flag[j]) {
            return NULL;
        }
    }
    write(1, &msg1, 1);
    msg1 = 0x4B;
    write(1, &msg1, 1);
    return NULL;
}

