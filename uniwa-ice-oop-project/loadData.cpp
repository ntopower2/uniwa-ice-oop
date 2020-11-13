
**char loadData(FILE* fp) {
    char *c1,*c2;
    char buff[1024];
    c1 = new char[40];
    c2 = new char[40];
    short cells=0,cell=0,row=0,letter=0;
    fgets(buff, sizeof(buff),fp);
    for (char c:buff) if (c==';') cells++;
    auto data = new char[cells+1][10][20];
    while (fgets(buff, sizeof(buff),fp)) {
        sscanf(buff, "%[^;];%[^;]",c1,c2);
        strcpy(data[cell][row],c1);cell++;
        strcpy(data[cell][row],c2);
        cell=0;row++;
    }
    //oldToNew[data[0][0]] = data[0][1];
    //oldToNew[data[1][1]] = data[1][1];
    delete[] c1;
    delete[] c2;
    fclose(fp);
    return &data;
}