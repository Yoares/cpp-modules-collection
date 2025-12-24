/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:58:41 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/07/30 21:36:12 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return 0;
    }
    if (ac >= 2)
    {
        for(int i = 1; i < ac; i++)
        {
            for(unsigned int j = 0; j < std::string(av[i]).length(); j++){
                std::cout << (char)std::toupper(av[i][j]);
            }
        }
    }
    std::cout << std::endl;
    return (0);
}
