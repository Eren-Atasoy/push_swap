
// overflow int underflow kontrol eklenecek
// duplicate sayı kontorlü eklenecek
arg_check(char **arg)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while(arg[i])
    {
        if ((arg[i][0] == '+' || arg[i][0] == '-') && (!arg[i][j+1]|| !arg[i][j+1]))
            error_handler("Error\n");
        while(arg[i] [j])
        {
            
            if (j > 0 && (arg[i][j] == '+' || arg[i][j] == '-'))
                error_handler("Error\n");
            
            if(!ft_isdigit(arg[i][j]) && (arg[i][j] != '+' || arg[i][j] != '-'))
                error_handler("Error\n");
            j++;
        }
    }
    if(!arg[i])
        error_handler("Error\n");
}