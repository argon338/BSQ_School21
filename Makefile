CUS_STR_SRC = custom_string.c ft_atoi.c ft_string.c

CUS_STR_DIR = custom_string

CUS_STR = ${addprefix ${CUS_STR_DIR}/,${CUS_STR_SRC}}

MAP_SRC = map_print.c

MAP_DIR = map_print

MAP = ${addprefix ${MAP_DIR}/,${MAP_SRC}}

PARCE_SRC = body_check.c header_check.c parce_file.c parce_line.c stdin_handler.c

PARCE_DIR = parcer

PARCE = ${addprefix ${PARCE_DIR}/,${PARCE_SRC}}

PLACEMENT_SRC = check_placement.c misc.c square_placement.c

PLACEMENT_DIR = placement_algorythm

PLACEMENT = ${addprefix ${PLACEMENT_DIR}/,${PLACEMENT_SRC}}

SRCS = ${CUS_STR} ${MAP} ${PARCE} ${PLACEMENT} BSQ.c

OBJS = ${SRCS:.c=.o}

HEAD = custom_string/custom_string.h map_print/map_print.h parcer/parcer.h placement_algorythm/placement_algorythm.h BSQ.h custom_struct.h

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = bsq

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CCFLAGS} ${OBJS} -o ${NAME}

%.o: %.c ${HEAD}
	${CC} ${CCFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean ${NAME}
