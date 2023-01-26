#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
typedef const char *string;

struct posicion
{
    int numero;
    int seek;
};
struct file {
    string path_name;
    struct stat struct_file;
    struct posicion pos;
    int fd;
};
int abrirArchivo(struct file *f);
int cerrarArchivo(struct file *f);
int estructuraArchivo(struct file *f);
void imprimeEstructuraArchivo(struct file *f);
int leerArchivo(struct file *f);
int contarPalabras(struct file *f, struct file *fsave);
int main(int argc, char** argv){

    struct file file1;
    int indicador = 0;
    file1.path_name = "help.txt";
    if(!strcmp(argv[2], "-l"))
        indicador = indicador | O_RDONLY  ;
    if(!strcmp(argv[2], "-e"))
        indicador = indicador | O_WRONLY;
    if(!strcmp(argv[2], "-le"))
        indicador = indicador | O_RDWR;
    indicador = indicador | O_CREAT;


    printf("indicador %d", indicador);
    abrirArchivo(&file1);
    //abrirArchivo(&file2);
    //leerArchivoOtroArchivo(&file1, &file2);
    //cerrarArchivo(&file1);
    cerrarArchivo(&file1);
    return 0;
}

int tamanioBuffer(string s){
    int i=0;
    while( s[i] !='\0' )
        i++;
    return i;
}
char getCaracter(struct file *f)
{
    int readbytes;
    char buffer;
    int c = f->pos.numero;
    int s = f->pos.seek;
    lseek(f->fd, c, s);
    //readbytes = read(f->fd, &buffer, 1);
    while(read(f->fd,&buffer,sizeof(buffer)!=0)){
        printf("%c",buffer);
        //printf("char: %c\tint: %d\tint: %u\tint: %i\toctal: %o\thexadecimal: %X",buffer,buffer,buffer,buffer,buffer,buffer );
    }
    f->pos.numero = f->pos.numero + 1;
    return buffer;
}
int leerLinea(struct file *f)
{
    int readbytes;
    int *buffer;
    lseek(f->fd, 0, SEEK_CUR);
}
int numeroLineas(string f1){
    int c;
    int i=0;

    FILE *file, *fopen();
    file = fopen(f1,"r");

    while( (c = getc(file)) != EOF){
        // putc(c, file);
        if(c == '\n')i++;
    }
    fclose(file);
    return i;
}
int contarPalabras(struct file *f, struct file *fsave)
{
    int readbytes;//la varible en la cual se almacenaran los caracteres o bytes leidos
    int i=0,j=0;
    char buffer[1];//buffer de escritura o lectura

    //lseek(file, 1, SEEK_SET);
    while((readbytes = read(f->fd, buffer, 1)) != 0){
        if(buffer[0] == '\n'){
            i++;
            //write(fsave->fd, buffer, 1);
            //printf("%s",i);
        }
    }
    string b = "hello";
    write(fsave->fd, b, tamanioBuffer(b));
    printf("\n Total de w es %d", i);

}
int abrirArchivo(struct file *f ) {

    if(( f->fd = open( f->path_name ,O_RDWR | O_CREAT, S_IRWXO | S_IRWXU | S_IRWXG ))== -1) {
        perror("open");
        exit(-1);
    }
    else {
        f->pos.numero = 0;
        f->pos.seek = SEEK_SET;
        return 1;
    }

}
int estructuraArchivo(struct file *f)
{
    if( (stat(f->path_name, &f->struct_file)) < 0)
    {
        perror("stat");
        return 0;
    }
    else return 1;

}
void imprimeEstructuraArchivo(struct file *f)
{/*
    printf( "\nPropiedades del fichero <%s>\n", f->path_name );
    printf("el fichero 1 abierto tiene el descriptor %d\n", f->fd);
    printf( "i-nodo: %d\n", f->struct_file.st_ino );
    printf( "dispositivo: %d, %d\n", major( f->struct_file.st_dev ),minor( f->struct_file.st_dev ) );
    printf( "modo: %#o\n", f->struct_file.st_mode );
    printf( "vinculos: %d\n", f->struct_file.st_nlink );
    printf( "propietario: %d\n", f->struct_file.st_uid );
    printf( "grupo: %d\n", f->struct_file.st_gid );
    printf( "tipo del dispositivo: %d\n", f->struct_file.st_rdev );
    printf( "tamaño total en bytes: %ld\n", f->struct_file.st_size );
    printf( "tamaño de bloque preferido: %d\n", f->struct_file.st_blksize );
    printf( "numero de bloques asignados: %d\n", f->struct_file.st_blocks );
    printf( "ultima hora de acceso: %s",ctime( &f->struct_file.st_atime ) );
    printf( "ultima hora de modificación: %s",ctime( &f->struct_file.st_mtime ) );
    printf( "ultima hora de cambio en inodo: %s",ctime( &f->struct_file.st_ctime ) );
*/
}
/* FUNCIONES*/
int leerArchivoPantalla(struct file *f)
{
    int readbytes;//la varible en la cual se almacenaran los caracteres o bytes leidos
    int i=0;
    int buffer[512];//buffer de escritura o lectura

    //lseek(file, 1, SEEK_SET);
    while((readbytes = read(f->fd, buffer, 512)) != 0){
        printf("\n interaciones: %d, readbytes: %d\n",i++, readbytes);
        write(1, buffer, readbytes);
    }
}
int cerrarArchivo(struct file *f)
{
    if(close(f->fd))
    {
        perror("close");
        return 0;
    }else return 1;

}