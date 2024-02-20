#define STR_BUF_LEN (11 + 1)

typedef struct TreeNode Tree;

static const char g_emptyCh = '\0';

static int max_int_2(const int val1, const int val2){
	return (val1 >= val2)? val1 : val2;
}

static int Tree_layer(const Tree * const pTree){
	if (NULL == pTree){
		return 0;
	}

	return 1 + max_int_2(
		Tree_layer(pTree->left),
		Tree_layer(pTree->right)
	);
}

static void printTree_recurse(
	const Tree * const pTree,
	char * * const * const layers,
	const int row,
	const int col,
	const int midOffset
){
	assert(pTree != NULL);

	char * const valStr = (char *)malloc(sizeof (char) * STR_BUF_LEN);
	sprintf(valStr, "%d", pTree->val);

	layers[row][col + midOffset] = valStr;

	if (pTree->left != NULL){
		printTree_recurse(pTree->left, layers, row + 1, col, midOffset / 2);
	}
	if (pTree->right != NULL){
		printTree_recurse(pTree->right, layers, row + 1, col + midOffset + 1, midOffset / 2);
	}
}

char * * * printTree(
	const Tree * const pTree,

	int * const pLayersLen, //out
	int * * const pLayerLens //out
){
	assert(pTree != NULL);

	const int layersLen = Tree_layer(pTree);
	const int layerLen = (1 << layersLen) - 1;

	*pLayersLen = layersLen;
	*pLayerLens = (int *)malloc(sizeof (int) * *pLayersLen);
	char * * * const layers = (char * * *)malloc(sizeof (char * *) * *pLayersLen);
	for (int i = 0; i < *pLayersLen; i += 1){
		(*pLayerLens)[i] = layerLen;
		layers[i] = (char * *)malloc(sizeof (char *) * (*pLayerLens)[i]);
		for (int j = 0; j < (*pLayerLens)[i]; j += 1){
			layers[i][j] = &g_emptyCh;
		}
	}

	printTree_recurse(pTree, layers, 0, 0, layerLen / 2);

	return layers;
}
