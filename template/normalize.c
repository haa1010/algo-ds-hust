void normalize(char *t)
{
    if (t[strlen(t) - 1] == 10)
        t[strlen(t) - 1] == '\0';
}