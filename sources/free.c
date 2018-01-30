/*
** free.c for  in /home/jaunet_n/Rendu/PSU_2016_malloc
** 
** Made by Nathan Jaunet
** Login   <jaunet_n@epitech.net>
** 
** Started on  Mon Jan 30 09:30:55 2017 Nathan Jaunet
** Last update Fri Feb 10 14:45:36 2017 Nathan Jaunet
*/

#include "malloc.h"

extern void		*base;
extern pthread_mutex_t	mutex;

t_block		*get_block_ptr(void *ptr)
{
  return (ptr - STRUCT_SIZE);
}

t_block		*fusion(t_block *block)
{
  if (block->next && block->next->free)
    {
      block->size += STRUCT_SIZE + block->next->size;
      block->next = block->next->next;
    }
  return (block);
}

void		free(void *ptr)
{
  t_block	*block_ptr;

  if (!ptr)
    return;
  block_ptr = get_block_ptr(ptr);
  pthread_mutex_lock(&mutex);
  block_ptr->free = 1;
  if (block_ptr->next)
    fusion(block_ptr);
  pthread_mutex_unlock(&mutex);
}
