#include "fildf.h"

t_coor update_x(int i, int j, int initx, int  inity)
{
    t_coor a;
    a.x = (4 *i) + initx;
    a.y = j + inity + (2*i) ;
    return a;
}
                                                                                                                                                                                                                      
void ft_drew_line(t_coor a,  t_coor b, mlx_image_t *img)                                                                                                                                                                                   
{                                                                                                                                                                                                                                          
    if( a.x == b.x && a.y == b.y )                                                                                                                                                                                                         
        return ;                                                                                                                                                                                                                           
    float dx = b.x - a.x;                                                                                                                                                                                                                  
    float dy = b.y - a.y;                                                                                                                                                                                                                  
    float max =  fmax(fabs(dx),fabs(dy));                                                                                                                                                                                                  
    int i = 0;
    while( (int)a.x != (int)b.x  && (int)a.y != (int)b.y  )
    {
        mlx_put_pixel(img, (int)a.x, (int)a.y, 0xFFFFFFFF);
        a .x += (dx /  max);
        a.y += (dy /max);
        i++;
    }
    return;
}

void ft_drew_map(t_fdf *fdf, mlx_image_t *img)
{
    int i = 0;
    int j = 0; 
    int delta = 10;
    int initx;
    int inity;

    while(j <= delta * fdf->width)
    {
        i = 0;
        initx = (WIDTH /2) - 2*j; 
        inity = 10 + j;  
        while( i <= fdf->height * delta)
        {
            t_coor a = update_x(i, j , initx, inity);
            t_coor b = update_x(i + delta, j , initx, inity);
            if(i + 1 < fdf->height * delta )  
                ft_drew_line(a,b,img);
            if(j + 1 < fdf->width * delta)
            {
                t_coor c = update_x(i, j + delta, initx  - (2 * delta), inity + delta);
                ft_drew_line(a, c, img);
            }
           i += delta;
        }
        j += delta;
    }   
}
