#ifdef __cplusplus
extern "C"
{
#endif


constexpr unsigned MAX_PARAMS_NUM = 128;
constexpr unsigned MAX_METHOD_PROPS_NUM = 256;

enum TableType { VARS, PARAMS, FUNCS, LITS, CLASSES, PROPS, LISTS };
enum DataType { UNKNOWN, NONE, NUM_BOOL, STRING };


typedef struct MainTable {
	unsigned index;
	TableType tableType;
} MainTable;


typedef struct FunctionsTable {
	char* name;
	bool isMethod;
	unsigned nonDefParamNum;
	unsigned defParamNum;
	unsigned defParamInds[MAX_PARAMS_NUM];
	unsigned nonDefParamInds[MAX_PARAMS_NUM];
} FunctionsTable;


typedef struct ClassesTable {
	char* name;
	char* selfName;
	unsigned methodsInds[MAX_METHOD_PROPS_NUM];
	unsigned propertiesInds[MAX_METHOD_PROPS_NUM];
} ClassesTable;


typedef struct PropertiesTable {
	char* name;
	bool isList;
	unsigned ind;
	DataType type;
} PropertiesTable;


typedef struct VariablesTable {
	char* name;
	bool isList;
	unsigned ind;
	DataType type;
} VariablesTable;


typedef struct ParametersTable {
	char* name;
	bool isList;
	unsigned ind;
	DataType type;
	bool hasDefVal;
} ParametersTable;


typedef struct LiteralsTable {
	char* value;
	DataType type;
} LiteralsTable;


typedef struct ListsTable {
	unsigned ind;
	bool hasNext;
	unsigned nextElemInd;
} ListsTable;



#ifdef __cplusplus
}
#endif