/*
** realloc.c for  in /home/jaunet_n/Rendu/PSU_2016_malloc
** 
** Made by Nathan Jaunet
** Login   <jaunet_n@epitech.net>
** 
** Started on  Mon Jan 30 09:32:16 2017 Nathan Jaunet
** Last update Sat Feb 11 13:36:45 2017 Nathan Jaunet
*/

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_block	*block_ptr;
  void		*new_ptr;

  size = align(size);
  if ((int)size <= 0)
    return (NULL);
  if (!ptr)
    return malloc(size);
  block_ptr = get_block_ptr(ptr);
  if (block_ptr->size >= size)
    return (ptr);
  new_ptr = malloc(size);
  if (!new_ptr)
    return (NULL);
  memcpy(new_ptr, ptr, block_ptr->size);
  free(ptr);
  return (new_ptr);
}
