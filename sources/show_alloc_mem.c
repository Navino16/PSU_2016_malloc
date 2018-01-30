/*
** show_alloc_mem.c for  in /home/jaunet_n/Rendu/PSU_2016_malloc
** 
** Made by Nathan Jaunet
** Login   <jaunet_n@epitech.net>
** 
** Started on  Mon Jan 30 09:52:04 2017 Nathan Jaunet
** Last update Wed Feb  1 11:36:49 2017 Nathan Jaunet
*/

#include "malloc.h"
#include <stdio.h>

extern void *base;

void	show_alloc_mem(void)
{
  t_block	*b;

  b = base;
  printf("break: %p\n", sbrk(0));
  while (b)
    {
      if (b->free == 0)
	printf("%p - %p : %d bytes\n", b, b + b->size, b->size);
      b = b->next;
    }
}
