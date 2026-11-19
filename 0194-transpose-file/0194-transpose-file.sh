awk '
{
    for (i = 1; i <= NF; i++)
        a[i] = (NR == 1 ? $i : a[i] " " $i)
}
END {
    for (i = 1; i <= NF; i++)
        print a[i]
}' file.txt