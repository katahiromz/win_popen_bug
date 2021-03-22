#include <stdio.h>

int main(void)
{
    FILE *fp;
    char buf[256];

    fp = _popen("cmdline.exe \"--test=TE ST\"", "rb"); /* SUCCESSFUL */
    if (fp)
    {
        while (fgets(buf, 256, fp))
        {
            fputs(buf, stdout);
        }
        _pclose(fp);
    }
    else
    {
        fprintf(stderr, "ERROR: Cannot execute 'cmdline.exe'\n");
        return -1;
    }

    fp = _popen("cmdline.exe \"--test=TE ST\"", "rb"); /* SUCCESSFUL */
    if (fp)
    {
        while (fgets(buf, 256, fp))
        {
            fputs(buf, stdout);
        }
        _pclose(fp);
    }
    else
    {
        fprintf(stderr, "ERROR: Cannot execute 'cm dline.exe'\n");
        return -2;
    }

    fp = _popen("\"cm dline.exe\" --test=TEST", "rb"); /* SUCCESSFUL */
    if (fp)
    {
        while (fgets(buf, 256, fp))
        {
            fputs(buf, stdout);
        }
        _pclose(fp);
    }
    else
    {
        fprintf(stderr, "ERROR: Cannot execute 'cm dline.exe'\n");
        return -2;
    }

    fp = _popen("\"cm dline.exe\" \"--test=TE ST\"", "rb"); /* BUG: this is failed */
    if (fp)
    {
        while (fgets(buf, 256, fp))
        {
            fputs(buf, stdout);
        }
        _pclose(fp);
    }
    else
    {
        fprintf(stderr, "ERROR: Cannot execute 'cm dline.exe'\n");
        return -2;
    }

    return 0;
}
