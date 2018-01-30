/*
** malloc for malloc in /home/jaunet_n/Rendu/PSU_2016_malloc
**
** Made by Nathan Jaunet
** Login   <jaunet_n@epitech.net>
**
** Started on Mon Jan 30 09:24:28 CET 2017 Nathan Jaunet
** Last update Wed Feb  1 11:04:00 2017 Nathan Jaunet
*/

#ifndef		MALLOC_H_
# define	MALLOC_H_

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

typedef struct s_block {
  size_t size;
  struct s_block *next;
  int free;
} t_block;

#define align(x) (((((x) -1) >>2) <<2) + 4)
#define STRUCT_SIZE (sizeof(struct s_block))

void            free(void *ptr);
void            *malloc(size_t size);
t_block         *get_block_ptr(void *ptr);
void		show_alloc_mem(void);

#endif /* MALLOC_H_ */
