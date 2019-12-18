/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colony.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: zseignon <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 11:45:38 by zseignon     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 13:55:00 by zseignon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COLONY_H
# define COLONY_H

# include "lem_in"

/*-----------------------------------------------------------------------------
 * VALID STRUCT
 */
struct						s_rlink
{
	int						n;
	struct s_rlink			*next;
};

struct						s_ant
{
	char					*used;
	struct s_rlink			*begin;
	struct s_rlink			*p;
	size_t					rlen;
	struct s_ant			*prev;
	struct s_ant			*next;
};

struct						s_colony
{
	struct s_ant			*ant;
	size_t					len;
};

typedef struct s_rlink		t_rlink;
typedef struct s_ant		t_ant;
typedef struct s_colony		t_colony;
typedef struct s_rclass		t_rclass;

/*-----------------------------------------------------------------------------
 * TMP STRUCT
 */

# define UP_TO_DATE			0x01

typedef struct				s_barr
{
	t_ul					*t;
	size_t					xlen;
}							t_barr;

typedef struct				s_rtab
{
	int						*t;
	size_t					len;
	struct s_rtab			*next;
}

typedef struct				s_rclass
{
	struct s_rtab			*begin;
	struct s_rtab			*p;
	size_t					len;
	t_barr					*matrix;
	int						value;
	t_byte					flag;
	struct s_rclass			*next;
}							t_rclass;

typedef struct				s_rclass_root
{
	struct s_rclass			*begin;
	struct s_rclass			*p;
	size_t					len;
}							t_rclass_root;

enum						r_eval
{
	PROCEED,
	STOP
};

/*----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
 * DONE
 */

int							colony_init(t_colony **c, t_anthill *ah, size_t n);
int							colony_free(t_colony **c);
int							colony_push(t_colony *dst, t_colony *src);

int							ant_spawn(t_colony *c, t_anthill *ah, size_t n);
int							ant_kill(t_colony *c);

int							barr_new(t_barr **b, char *t, size_t len);
int							barr_cmp(t_barr *b1, t_barr *b2);
int							barr_fusion(t_barr *dst, t_barr *src);

int							tube_count(int room, t_anthill *ah);

/*---------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
 * TO DO
 */


//SOMEWHERE IN CODE
int							road_classify(t_colony *c, t_rclass *rc, t_anthill *ah);


//ASSUMPTION
int							rclass_new(t_rclass **new, t_anthill *ah);
int							roadmap_init(t_ant 

/*---------------------------------------------------------------------------*/













#endif
