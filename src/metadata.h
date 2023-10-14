struct MetaInfo {
    int columns_count;
    struct Columninfo columns[SIZE];
};

struct ColumnInfo {
    char name[SIZE_OF_NAME];
    int type;
};
