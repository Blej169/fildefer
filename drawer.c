#include "fildf.h"

t_coor update_x(int i, int j, int initx, int  inity, t_data data)
{
    t_coor a;
    a.x = (2 *i) + initx;
    a.y = j + inity + i - (data.z * 2);
    return a;
}
                                                                                                                                                                                                                      
void ft_drew_line(t_coor a,  t_coor b, mlx_image_t *img , t_data data)                                                                                                                                                                                   
{                                                                                                                                                                                                                                          
    if( a.x == b.x && a.y == b.y )                                                                                                                                                                                                         
        return ;
    float dx = b.x - a.x;                                                                                                                                                                                                               
    float dy = b.y - a.y;
    float max = fmax(fabs(dx),fabs(dy));                                                                                                                                                                                                  
    int i = 0;
    if((int)dx == 0 || (int)dy == 0)
    {
        while( (int)a.x != (int)b.x  || (int)a.y != (int)b.y )
        {
            if(((int)a.x > 0 && (int)a.x < WIDTH) && ((int)a.y > 0 && (int)a.y < HEIGHT))
                mlx_put_pixel(img, (int)a.x, (int)a.y, data.color);
            a.x += (dx/max);
            a.y += (dy/max);
            i++;
        }
        return ;
    }
    while( (int)a.x != (int)b.x  && (int)a.y != (int)b.y )
    {
        if(((int)a.x > 0 && (int)a.x < WIDTH) && ((int)a.y > 0 && (int)a.y < HEIGHT))
            mlx_put_pixel(img, (int)a.x, (int)a.y, data.color);
        a.x += (dx/max);
        a.y += (dy/max);
        i++;
    }
    return;
}

void ft_drew_map(t_fdf *fdf, mlx_image_t *img)
{
    int i = 0;
    int j = 0; 
    int x = 0;
    int y = 0;
    float delta = 2;
    int initx;
    int inity;
    t_data **data; 

    data = fdf->data;
    while(j < delta * fdf->height)
    {
        i = 0;
        y = (int)(j/delta);
        initx = (WIDTH /2) - 2*j;
        inity =  10 + j - 50;
        while( i < fdf->width * delta)
        {
            x = (int)(i/delta);
            t_coor a = update_x(i, j , initx, inity,data[y][x]);
            t_coor b = update_x(i + delta, j , initx, inity, data[y][x + 1]);
            if(i + delta < fdf->width * delta )
            {
                ft_drew_line(a,b,img,data[y][x]);
            }
            if(j + delta < fdf->height * delta)
            {
                t_coor c = update_x(i, j + delta, initx  - (2 * delta), inity + delta,data[y+1][x]);
                ft_drew_line(a, c, img, data[y][x]);
            }
           i += delta;    
        }
        j += delta;
    }
}
