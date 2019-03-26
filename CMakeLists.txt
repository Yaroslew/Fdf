cmake_minimum_required(VERSION 3.13)
project(fdf_ver_2_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(fdf_ver_2_0 main.c header.h valid.c
        libft/get_next_line.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strndup.c
        libft/ft_strcat.c libft/ft_strlen.c libft/ft_strnew.c libft/ft_bzero.c record_map.c
        libft/ft_strsplit.c libft/ft_atoi.c)