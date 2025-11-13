unsigned char kb_map[256];
void kb_map_init(void){
    for(int i=0;i<256;i++) kb_map[i]=0;
    kb_map[0x02]='1'; kb_map[0x03]='2'; kb_map[0x04]='3'; kb_map[0x05]='4';
    kb_map[0x06]='5'; kb_map[0x07]='6'; kb_map[0x08]='7'; kb_map[0x09]='8';
    kb_map[0x0A']='9'; kb_map[0x0B']='0'; kb_map[0x10]='q'; kb_map[0x11]='w';
    kb_map[0x12]='e'; kb_map[0x13]='r'; kb_map[0x14]='t'; kb_map[0x15]='y';
    kb_map[0x16]='u'; kb_map[0x17]='i'; kb_map[0x18]='o'; kb_map[0x19]='p';
    kb_map[0x1E]='a'; kb_map[0x1F]='s'; kb_map[0x20]='d'; kb_map[0x21]='f';
    kb_map[0x22]='g'; kb_map[0x23]='h'; kb_map[0x24]='j'; kb_map[0x25]='k';
    kb_map[0x26]='l'; kb_map[0x2C]='z'; kb_map[0x2D]='x'; kb_map[0x2E]='c';
    kb_map[0x2F]='v'; kb_map[0x30]='b'; kb_map[0x31]='n'; kb_map[0x32]='m';
    kb_map[0x1C]='\n'; kb_map[0x0E]='\b';
}
