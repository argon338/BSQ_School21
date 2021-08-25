#include "../BSQ.h"
#include <unistd.h>
#include <stdlib.h>

char	*stdin_to_string(void)
{
	char	*file_data;
	char	buf;
	int		read_error;
	int		memsize;

	memsize = 4;
	file_data = (char *) malloc(sizeof(char) * memsize);
	if (file_data == NULL)
		return (NULL);
	ft_empty_string(file_data, memsize);
	read_error = read(0, &buf, 1);
	while (read_error != 0)
	{
		if (read_error < 0)
		{
			free(file_data);
			return (NULL);
		}
		file_data = ft_char_push_back(file_data, buf, &memsize);
		if (file_data == NULL)
			return (NULL);
		read_error = read(0, &buf, 1);
	}
	return (file_data);
}