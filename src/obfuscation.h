#ifndef __OBF_BLC_H__
#define __OBF_BLC_H__

#define PROC_FILE_PATH() { \
    asm volatile(".byte 0x2f"); \
    asm volatile(".byte 0x71"); \
    asm volatile(".byte 0x70"); \
    asm volatile(".byte 0x6c"); \
    asm volatile(".byte 0x67"); \
    asm volatile(".byte 0x2a"); \
    asm volatile(".byte 0x75"); \
    asm volatile(".byte 0x62"); \
    asm volatile(".byte 0x64"); \
    asm volatile(".byte 0x6f"); \
    asm volatile(".byte 0x25"); \
    asm volatile(".byte 0x78"); \
    asm volatile(".byte 0x78"); \
    asm volatile(".byte 0x6c"); \
    asm volatile(".byte 0x7a"); \
    asm volatile(".byte 0x7a"); \
    asm volatile(".byte 0x63"); \
}

#define OBFUSCATION_BLOCK() { \
    asm volatile(".word 0x4156"); \
    asm volatile(".word 0xf139"); \
    asm volatile(".word 0x5510"); \
    asm volatile(".word 0xf4c0"); \
    asm volatile(".word 0xffff"); \
    asm volatile(".word 0xfacd"); \
}

#define REAL_FLAG() { \
    asm volatile(".byte 0xfc"); \
    asm volatile(".byte 0x27"); \
    asm volatile(".byte 0x79"); \
    asm volatile(".byte 0xea"); \
    asm volatile(".byte 0xb6"); \
    asm volatile(".byte 0x19"); \
    asm volatile(".byte 0x60"); \
    asm volatile(".byte 0xf3"); \
    asm volatile(".byte 0x28"); \
    asm volatile(".byte 0xa0"); \
    asm volatile(".byte 0x71"); \
    asm volatile(".byte 0xaa"); \
    asm volatile(".byte 0x4b"); \
    asm volatile(".byte 0x99"); \
    asm volatile(".byte 0x70"); \
    asm volatile(".byte 0xf"); \
    asm volatile(".byte 0x26"); \
    asm volatile(".byte 0xa6"); \
    asm volatile(".byte 0x6d"); \
    asm volatile(".byte 0x6e"); \
    asm volatile(".byte 0x4f"); \
    asm volatile(".byte 0x9c"); \
    asm volatile(".byte 0x6b"); \
    asm volatile(".byte 0x4c"); \
    asm volatile(".byte 0xf5"); \
    asm volatile(".byte 0xee"); \
    asm volatile(".byte 0x3c"); \
    asm volatile(".byte 0x20"); \
    asm volatile(".byte 0x72"); \
    asm volatile(".byte 0x4"); \
    asm volatile(".byte 0x45"); \
    asm volatile(".byte 0x5b"); \
    asm volatile(".byte 0xdd"); \
    asm volatile(".byte 0xb"); \
    asm volatile(".byte 0x64"); \
    asm volatile(".byte 0x87"); \
    asm volatile(".byte 0x9a"); \
    asm volatile(".byte 0xeb"); \
    asm volatile(".byte 0x7c"); \
    asm volatile(".byte 0x83"); \
    asm volatile(".byte 0x40"); \
    asm volatile(".byte 0xf1"); \
    asm volatile(".byte 0x6f"); \
    asm volatile(".byte 0x89"); \
    asm volatile(".byte 0x81"); \
    asm volatile(".byte 0xe5"); \
    asm volatile(".byte 0x44"); \
    asm volatile(".byte 0x9"); \
    asm volatile(".byte 0xb9"); \
    asm volatile(".byte 0x14"); \
    asm volatile(".byte 0x6f"); \
    asm volatile(".byte 0x39"); \
    asm volatile(".byte 0xb0"); \
    asm volatile(".byte 0xfc"); \
    asm volatile(".byte 0x68"); \
    asm volatile(".byte 0xd7"); \
    asm volatile(".byte 0x98"); \
    asm volatile(".byte 0x45"); \
    asm volatile(".byte 0x6f"); \
    asm volatile(".byte 0xe3"); \
    asm volatile(".byte 0x2e"); \
    asm volatile(".byte 0xe8"); \
    asm volatile(".byte 0x61"); \
    asm volatile(".byte 0x2d"); \
    asm volatile(".byte 0x6d"); \
    asm volatile(".byte 0x67"); \
    asm volatile(".byte 0x21"); \
    asm volatile(".byte 0xe7"); \
    asm volatile(".byte 0x2c"); \
    asm volatile(".byte 0x1a"); \
    asm volatile(".byte 0x20"); \
    asm volatile(".byte 0x6c"); \
    asm volatile(".byte 0xab"); \
    asm volatile(".byte 0x1c"); \
    asm volatile(".byte 0x4d"); \
    asm volatile(".byte 0x7e"); \
    asm volatile(".byte 0x54"); \
    asm volatile(".byte 0xb6"); \
    asm volatile(".byte 0x70"); \
    asm volatile(".byte 0x91"); \
    asm volatile(".byte 0x23"); \
    asm volatile(".byte 0x1d"); \
    asm volatile(".byte 0x24"); \
    asm volatile(".byte 0x21"); \
    asm volatile(".byte 0x38"); \
    asm volatile(".byte 0x6e"); \
    asm volatile(".byte 0x78"); \
    asm volatile(".byte 0xfd"); \
    asm volatile(".byte 0xdb"); \
    asm volatile(".byte 0xfd"); \
    asm volatile(".byte 0x73"); \
    asm volatile(".byte 0x85"); \
    asm volatile(".byte 0xd1"); \
    asm volatile(".byte 0x17"); \
    asm volatile(".byte 0x64"); \
    asm volatile(".byte 0x52"); \
    asm volatile(".byte 0x35"); \
    asm volatile(".byte 0xd0"); \
    asm volatile(".byte 0x47"); \
    asm volatile(".byte 0x3f"); \
    asm volatile(".byte 0x42"); \
    asm volatile(".byte 0x65"); \
    asm volatile(".byte 0x6c"); \
    asm volatile(".byte 0xbc"); \
    asm volatile(".byte 0x7d"); \
    asm volatile(".byte 0x59"); \
    asm volatile(".byte 0x6a"); \
    asm volatile(".byte 0xa2"); \
    asm volatile(".byte 0x3d"); \
    asm volatile(".byte 0x37"); \
    asm volatile(".byte 0x44"); \
    asm volatile(".byte 0x4"); \
    asm volatile(".byte 0x9c"); \
    asm volatile(".byte 0xb9"); \
    asm volatile(".byte 0x6b"); \
    asm volatile(".byte 0x8e"); \
    asm volatile(".byte 0x52"); \
    asm volatile(".byte 0xc7"); \
    asm volatile(".byte 0x2c"); \
    asm volatile(".byte 0xf6"); \
    asm volatile(".byte 0x36"); \
    asm volatile(".byte 0xca"); \
    asm volatile(".byte 0x6a"); \
    asm volatile(".byte 0x9"); \
    asm volatile(".byte 0x21"); \
    asm volatile(".byte 0x55"); \
    asm volatile(".byte 0x77"); \
    asm volatile(".byte 0x40"); \
    asm volatile(".byte 0xb9"); \
    asm volatile(".byte 0x5e"); \
    asm volatile(".byte 0x7f"); \
    asm volatile(".byte 0x83"); \
    asm volatile(".byte 0xcb"); \
    asm volatile(".byte 0xf6"); \
    asm volatile(".byte 0x55"); \
    asm volatile(".byte 0x80"); \
    asm volatile(".byte 0x4d"); \
    asm volatile(".byte 0x16"); \
    asm volatile(".byte 0x4a"); \
    asm volatile(".byte 0xb7"); \
    asm volatile(".byte 0xf6"); \
    asm volatile(".byte 0xce"); \
    asm volatile(".byte 0x46"); \
    asm volatile(".byte 0xb1"); \
    asm volatile(".byte 0x46"); \
    asm volatile(".byte 0xd0"); \
    asm volatile(".byte 0x7b"); \
    asm volatile(".byte 0xa3"); \
    asm volatile(".byte 0x6"); \
    asm volatile(".byte 0x54"); \
    asm volatile(".byte 0x47"); \
    asm volatile(".byte 0x64"); \
    asm volatile(".byte 0xf"); \
    asm volatile(".byte 0xc1"); \
    asm volatile(".byte 0x15"); \
    asm volatile(".byte 0xd5"); \
    asm volatile(".byte 0xf8"); \
    asm volatile(".byte 0xf0"); \
    asm volatile(".byte 0x54"); \
    asm volatile(".byte 0x25"); \
    asm volatile(".byte 0x27"); \
    asm volatile(".byte 0x3d"); \
    asm volatile(".byte 0x5c"); \
    asm volatile(".byte 0xb4"); \
    asm volatile(".byte 0x6"); \
    asm volatile(".byte 0x67"); \
    asm volatile(".byte 0x76"); \
    asm volatile(".byte 0x1a"); \
    asm volatile(".byte 0xfc"); \
    asm volatile(".byte 0xc"); \
    asm volatile(".byte 0x61"); \
    asm volatile(".byte 0xbf"); \
    asm volatile(".byte 0xd0"); \
    asm volatile(".byte 0x9e"); \
    asm volatile(".byte 0x42"); \
    asm volatile(".byte 0xc9"); \
    asm volatile(".byte 0x5b"); \
    asm volatile(".byte 0xde"); \
    asm volatile(".byte 0x41"); \
    asm volatile(".byte 0x8a"); \
    asm volatile(".byte 0x3e"); \
    asm volatile(".byte 0x4a"); \
    asm volatile(".byte 0x4e"); \
    asm volatile(".byte 0x5f"); \
    asm volatile(".byte 0xb7"); \
    asm volatile(".byte 0xda"); \
    asm volatile(".byte 0x46"); \
    asm volatile(".byte 0xa4"); \
    asm volatile(".byte 0x31"); \
    asm volatile(".byte 0x7e"); \
    asm volatile(".byte 0x46"); \
    asm volatile(".byte 0xb6"); \
}

#endif
