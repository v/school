#define FUSE_USE_VERSION 26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <fuse/fuse.h>


FILE *fp;
 
// FUSE function implementations.
static int mathfs_getattr(const char *path, struct stat *stbuf)
{
	//printf("Getattr Path: %s\n", path);
}

static int mathfs_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset,
			struct fuse_file_info *fi)
{
    (void) offset;
    (void) fi;

	//printf("Readdir Path: %s\n", path);

	printf("****BROSKIII I JUST PRINTED THIS OUT****\n");

}		

static int mathfs_open(const char *path, struct fuse_file_info *fi)
{
	//printf("Open Path: %s\n", path);

}

static int mathfs_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi)
{
    (void) fi;

	printf("Read Path: %s\n", path);
}

static struct fuse_operations mathfs_oper = {
    .getattr = mathfs_getattr,
    .readdir = mathfs_readdir,
    .open = mathfs_open,
    .read = mathfs_read,
};

int main(int argc, char **argv)
{
	fp = fopen("output", "a");
    return fuse_main(argc, argv, &mathfs_oper, NULL);
}

