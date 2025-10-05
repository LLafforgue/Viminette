#include <unistd.h>

void	ft_atest()

void	ft_test(void)
{
	wrtite(1, "ceci est un test", 16);
}
int	main(void)
{
	ft_test()

		n! FTDynamicComplete(findstart, base)
		    if a:findstart
				        " Trouver le début du mot sous le curseur
							        let line = getline('.')
									        let start = col('.') - 1
											        while start > 0 && line[start - 1] =~ '\k'
														            let start -= 1
																		        endwhile
																				        return start
																						    else
																								        " Déterminer le préfixe dynamiquement
																											        " Ici on prend le mot courant (a:base) et on vérifie s'il commence par ft_
																													        let prefix = a:base

																															        " Créer une liste pour stocker les matches
																																	        let l:matches = []

																																			        " Parcourir toutes les lignes du buffer
																																					        for l in getbufline('%', 1, '$')

																																								            " Chercher toutes les occurrences de ft_xxx (noms valides)
																																												            for m in matchlist(l, '\v(ft_[A-Za-z0-9_]+)')
																																																                if !empty(m[1]) && m[1] =~ '^' . prefix
																																																					                    if index(l:matches, m[1]) < 0
																																																											                        call add(l:matches, m[1])
																																																																		                    endif
																																																																							                endif
																																																																											            endfor
																																																																														        endfor

																																																																																        return sort(l:matches)
																																																																																		    endif
																																																																																			endfunction
	write(1, "42!\\n", 4);
	return (0);
}

