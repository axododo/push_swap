int *sa(int *a) {
    int tmp;
    tmp = a[1];
    a[2] =a[1];
    a[2] = tmp;
    return (a);
}
int *sb(int *b) {
    int tmp;
    tmp = a[1];
    b[2] =a[1];
    b[2] = tmp;
    return (a);
}
int *ss(int *a, int *b) {
    b = *sb(int *b);
    a = *sa(int *a);
    return (a);
}