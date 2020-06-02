#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>

#define LIST 1
#define INODE 2
#define RECUR 4
#define ALL 8

void printInfo(char *);
void printTime(const time_t *time) {
    struct tm *tmp = localtime(time);
    printf("%04d-%02d-%02d- %02d:%02d ", tmp->tm_year+1900, tmp->tm_mon+1, tmp->tm_mday, 
        tmp->tm_hour, tmp->tm_min);
}


void my_ls(char *dname) {
    DIR *dp;
    struct dirent *p;
    struct stat buf;
    chdir(dname);
    dp = opendir(".");
    while(p = readdir(dp))
        printInfo(p->d_name);

    rewinddir(dp);
    while(p = readdir(dp)) {
        lstat(p->d_name, &buf);
        if(S_ISDIR(buf.st_mode)) {
            if(strcmp (p->d_name, ".") && ( strcmp(p->d_name, "..")))
                my_ls(p->d_name);
        }
    }
    closedir(dp);
    chdir("..");
}

void printInfo(char *name) {
    struct stat buf;
    struct passwd *pwd;
    struct group *grp;
    char perm[11] = "----------";
    char rwx[3]="rwx";
    int i;
    stat(name, &buf);
    if( S_ISDIR(buf.st_mode))
        perm[0] = 'd';
    if( S_ISDIR(buf.st_mode))
        perm[0] = 'c';
    if( S_ISDIR(buf.st_mode))
        perm[0] = 'b';
    if( S_ISDIR(buf.st_mode))
        perm[0] = 's';
    if( S_ISDIR(buf.st_mode))
        perm[0] = 'l';
    if( S_ISDIR(buf.st_mode))
        perm[0] = 'p';

    for(i=0; i<9; i++)
    {
        if((buf.st_mode >>(8-i)) & 0x1)
            perm[i+1] = rwx[i%3];
    }
    printf("%s", perm);

    printf("%*d", 3, (int)buf.st_nlink);

    pwd = getpwuid(buf.st_uid);
    printf(" %s", pwd->pw_name);

    grp = getgrgid(buf.st_gid);
    printf(" %s", grp->gr_name);

    if(perm[0]=='c' || perm[0]=='b')
    {
        printf(" %d, %d",(int) (buf.st_rdev>>8)&0xff, (int)buf.st_rdev&0xff);
    }
    else
    {
        printf(" %d", (int)buf.st_size);
    }
   // printTime(&buf.st_mtime);
    printf(" %s", ctime(&buf.st_mtime));
    if(perm[0] != 'l')
        printf(" %s\n", name);
    else
    {
        int ret;
        char temp[100];
        ret = readlink(name, temp, sizeof temp);
        temp[ret]=0;
        printf(" %s -> %s\n", name, temp);
    }
}

int main(int argc, char **argv) {
    int ch;
    int flag=0;
    while((ch = getopt(argc, argv, "liRa"))!= -1)
    {
        switch(ch) {
            case 'l': flag |= LIST; break;
            case 'i': flag |= INODE; break;
            case 'R': flag |= RECUR; break;
            case 'a': flag |= ALL; break;
        }
    }
    if(flag & LIST);
    my_ls(".");
    return 0;
}
