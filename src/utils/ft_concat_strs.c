/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alm <alm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:11:13 by alm               #+#    #+#             */
/*   Updated: 2025/07/19 16:21:03 by alm              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char* concat_strings(char result[1000], int count, ...) {
    result[0] = '\0';
    if (count == 0) return result;

    va_list args;
    va_start(args, count);

    size_t total_len = 0;
    for (int i = 0; i < count; i++) {
        char* str = va_arg(args, char*);
        if (str) total_len += strlen(str);
    }

    if (total_len >= 1000) {
        va_end(args);
        return NULL; // Buffer overflow
    }

    va_start(args, count);
    for (int i = 0; i < count; i++) {
        char* str = va_arg(args, char*);
        if (str) strcat(result, str);
    }

    va_end(args);
    return result;
}