#include <stdio.h>
#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"

struct _Point {
 int x, y;
 char symbol;
 bool visited;
};

struct _Maze {
 int ncols, nrows;
 Point *in, *out;
 Point **map;
};


Point *point_new(int x, int  y, char symbol){
    Point *p = (Point*)malloc(1*sizeof(Point));
    if(!p)
    return NULL;

    if(x<0 || y<0 || !symbol){
        free(p);
        return NULL;
    }

    p->x = x;
    p->y = y;
    p->symbol = symbol;
  

    return p;
}

void point_free(Point *p){
    free(p);
}

int point_getX(const Point *p){
    if (p==NULL)
    {
        return INT_MAX;
    }
    return p->x;
}

int point_getY(const Point *p){
    if (p==NULL)
    {
        return INT_MAX;
    }
    return p->y;
}

char point_getSymbol(const Point *p){
    if (p==NULL)
    {
        return ERRORCHAR;
    }
    return p->symbol;
}

bool point_getVisited(const Point *p){
    if (p==NULL){
        return ERRORCHAR;
    }

    return p->visited;
}

Status point_setX(Point *p, int x){
    if (x<0){
        return ERROR;
    }
    p->x=x;

    return OK;

}

Status point_setY(Point *p, int y){
    if (y<0){
        return ERROR;
    }
    p->y=y;

    return OK;

}

Status point_setSymbol(Point *p, char c){
    if ((c != WALL) && (c != IN) && (c != OUT) && (c != SPACE)){
        return ERRORCHAR;
    }
    p->symbol=c;

    return OK;

}

Status point_setVisited(Point *p, bool visited){
    if (p==NULL){
        return ERRORCHAR;
    }
    p->visited=visited;

    return OK;
}

Point *point_hardcpy(const Point *src){
    Point *v;
    if ((v=(Point*)malloc(1* sizeof(Point)))==NULL){
        return NULL;
    }

    point_setX(v, src->x);
    point_setY(v, src->y);
    if (point_setSymbol(v, src->symbol)==ERROR)
    {
        printf("ERROR");
    }
    return v;

}

bool point_equal(const void *p1, const void *p2){
    const Point* a;
    const Point* b;

    if(!p1||!p2){
        return ERROR;
    }
        
    a = (const Point*)p1;
    b = (const Point*)p2;
    if((point_getX(a)==point_getX(b))&&(point_getY(a)==point_getY(b))&&(point_getSymbol(a)==point_getSymbol(b))&&(point_getVisited(a)==point_getVisited(b))){
        return true;
    }
    return false;
}

int point_print(FILE *pf, const void *p){
    const Point* a;
    int num_printed;
    a = (const Point*)p;
    if (p==NULL)
    {
        return 0;
    }
    num_printed = 0;

    num_printed = fprintf(pf, "[(%d, %d): %c]", a->x, a->y, a->symbol);

    return num_printed;
}


Maze *maze_new(int nrows, int ncols){
    Maze *m;
    int i,j,x,y;

    if ((m=(Maze*)calloc(1, sizeof(Maze)))==NULL){
        return NULL;
    }

    m->nrows=nrows;
    m->ncols=ncols;
    if ((m->map = (Point**)calloc(nrows, sizeof(Point*))) == NULL) {
        free(m);
        return NULL;
    }   

    for (i = 0; i < nrows; i++)
    {
        if(((m->map[i])=(Point*)calloc(ncols,sizeof(Point)))==NULL)
        {
            for (j = 0; j< i; j++)
            {
                free(m->map[j]);
            }
            free(m->map);
            free(m);
            
            return NULL;
        }
        
    }
    
    for(x=0; x<nrows; x++){
        for (y = 0; y < ncols; y++)
        {
            point_setX(&m->map[x][y], x);
            point_setY(&m->map[x][y], y);
            point_setSymbol(&m->map[x][y], SPACE);
            point_setVisited(&m->map[x][y], false);
        }
    } 

    return m;
}

void maze_free(Maze *maze){
    int i;
    for(i=0; i<maze->nrows; i++){
        free(maze->map[i]);
    }
    free(maze->map);
    free(maze);
}

Point *maze_getPoint(const Maze *maze, int x, int y){
    if (maze_checkCoordinates(maze, x, y)==ERROR)
    {
        printf("FUERA DE MAPA");
        return NULL;
    }
    return &maze->map[x][y];
}

Status maze_setSymbol(const Maze *maze, int x, int y, char sym){
    if (sym != WALL && sym != IN && sym != OUT && sym != SPACE){
        return ERRORCHAR;
    }
    maze->map[x][y].symbol=sym;
    return OK;   
}

Status maze_setVisited(const Maze *maze, int x, int y, bool visited){
    if ((point_setVisited(maze_getPoint(maze, x, y), visited)==ERRORCHAR)){
        return ERRORCHAR;
    }
    return OK;   
}

char maze_getSymbol(const Maze *maze, int x, int y){
    if (maze==NULL)
    {
        return ERRORCHAR;
    }
    return point_getSymbol(maze_getPoint(maze, x, y));
}

bool maze_isVisited(const Maze *maze, int x, int y){
    if (maze==NULL)
    {
        return false;
    }
    return point_getVisited(maze_getPoint(maze, x, y));
}

Status maze_setIn(Maze *maze, int x, int y){
    if (maze==NULL || point_setSymbol(maze_getPoint(maze, x, y), IN)==ERROR)
    {
        return ERROR;
    }
    maze->in = &maze->map[x][y];
    return OK;
}

Status maze_setOut(Maze *maze, int x, int y){
    if (maze==NULL || point_setSymbol(maze_getPoint(maze, x, y), OUT)==ERROR)
    {
        return ERROR;
    }
    maze->out = &maze->map[x][y];
    return OK;
}

Point *maze_getIn(const Maze *maze){
    if (maze!=NULL)
    {
        return maze->in;
    }
    
    return NULL;
}

Point *maze_getOut(const Maze *maze){
    if (maze!=NULL)
    {
        return maze->out;
    }
    
    return NULL;
}

int maze_getNrows(const Maze *maze){
    if(maze==NULL){
        return ERROR;
    }
    return maze->nrows;
}

int maze_getNcols(const Maze *maze){
    if(maze==NULL){
        return ERROR;
    }
    return maze->ncols;
}

Point *maze_getNeighbor(const Maze *maze, const Point *p, direction dir){
    if(maze==NULL||p==NULL){
        return NULL;
    }
    switch (dir)
    {
    case RIGHT:
        if ((maze_checkCoordinates(maze, point_getX(p), point_getY(p)+2)==OK))
        {
            return maze_getPoint(maze, p->x, (p->y)+1);
        }
        break;
    case UP:
        if ((maze_checkCoordinates(maze, point_getX(p)-1, point_getY(p))==OK))
        {
            return maze_getPoint(maze, (p->x)-1, p->y);
        }
        break;
    case LEFT:
        if ((maze_checkCoordinates(maze, point_getX(p), point_getY(p)-1)==OK))
        {
            return maze_getPoint(maze, p->x, (p->y)-1);
        }
        break;
    case DOWN:
        if ((maze_checkCoordinates(maze, point_getX(p)+1, point_getY(p))==OK))
        {
            return maze_getPoint(maze, (p->x)+1, p->y);
        }
        break;
    case STAY:
        if ((maze_checkCoordinates(maze, point_getX(p), point_getY(p))==OK))
        {
            return maze_getPoint(maze, p->x, p->y);
        }
        break;

    default:
        return NULL;
        break;

    }
    return NULL;
}

Status maze_checkCoordinates(const Maze *maze, int x, int y){
    if (maze==NULL||y>=maze_getNcols(maze)||x<0||x>=maze_getNrows(maze)||y<0)
    {
        return ERROR;
    }
    return OK;
}


int maze_printPoints(FILE *fp, const Maze *maze){
    int i, j;
    if (maze==NULL)
    {
        return ERROR;
    }
    for ( i = 0; i < maze_getNrows(maze); i++)
    {
        for ( j = 0; j < maze_getNcols(maze); j++)
        {
            point_print(fp, maze_getPoint(maze, i, j));
        }
        fprintf(fp, "\n");
        
    }
    return OK;
}

int maze_print(FILE *fp, const Maze *maze){
    int i, j;
    if (maze==NULL)
    {
        return ERROR;
    }
    for ( i = 0; i < maze_getNrows(maze); i++)
    {
        for ( j = 0; j < maze_getNcols(maze); j++)
        {   
            if(point_getSymbol(maze_getPoint(maze, i, j))==IN||point_getSymbol(maze_getPoint(maze, i, j))==OUT){
                point_print(fp, maze_getPoint(maze, i, j));
                fprintf(fp, " ");
            }
        }
        
    }
    printf("\n");
    for ( i = 0; i < maze_getNrows(maze); i++)
    {
        for ( j = 0; j < maze_getNcols(maze); j++)
        {
            fprintf(fp, "%c", point_getSymbol(maze_getPoint(maze, i, j)));
        }
        fprintf(fp, "\n");
    }
    return OK;
}

Maze *maze_readFromFile(const char *filename){
    FILE *f;
    Maze *m;
    int nrows, ncols;
    int i, j;
    char sym;
    
    if((f=fopen(filename, "r"))==NULL){
        return NULL;
    }
    fscanf(f, "%d %d", &nrows, &ncols);
    if((m=maze_new(nrows, ncols))==NULL){
        fclose(f);
        return NULL;
    }
    for ( i = 0; i < nrows; i++)
    {
        for ( j = 0; j < ncols; j++)
        {
            fscanf(f, "\n%c", &sym);
            maze_setSymbol(m, i, j, sym);
            if (sym==OUT)
            {
                maze_setOut(m, i, j);
            }
            if (sym==IN)
            {
                maze_setIn(m, i, j);
            }
            
            
        }
    }
    fclose(f);
    return m;
}