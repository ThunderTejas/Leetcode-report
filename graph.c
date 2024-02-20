// Specification of queue:

typedef struct node {
    int val;
    struct node *next;
} node;

typedef struct queue {
    int size;
    node *head;
    node *last;
} queue;

// Implementation queue:

queue* init() {
    queue *q = malloc(sizeof(queue));
    q->size = 0;
    q->head = NULL;
    q->last = NULL;
    return q;
}

bool is_empty_queue(queue *q) {
    return q->size == 0;
}

void enqueue(queue *q, int value) {
    node *tmp = malloc(sizeof(node));
    tmp->val = value;
    tmp->next = NULL;
    if (is_empty_queue(q)) {
        q->head = tmp;
        q->last = tmp;
    } else {
        q->last->next = tmp;
        q->last = q->last->next;
    }
    q->size++;
}

// Precondition: !is_empty_queue(q).
int dequeue(queue *q) {
    assert(!is_empty_queue(q));
    node *tmp = q->head;
    int value = tmp->val;
    q->head = q->head->next;
    q->size--;
    free(tmp);
    return value;
}

// Enumerate for the colors:

typedef enum color {
    UNVISITED = 0,
    BLUE = 1,
    RED = 2,
} color;

// Algorithm:

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    queue *queueIndex = init();
    color *colorArray = calloc(graphSize, sizeof(color));
    memset(colorArray, UNVISITED, graphSize * sizeof(color));

    for (int index = 0; index < graphSize; index++) {
        if (colorArray[index] != UNVISITED) continue;
        enqueue(queueIndex, index);
        colorArray[index] = BLUE;
        while (!is_empty_queue(queueIndex)) {
            int vertexIndex = dequeue(queueIndex);
            for (int i = 0; i < graphColSize[vertexIndex]; i++) {
                int neighborIndex = graph[vertexIndex][i];
                if (colorArray[neighborIndex] == UNVISITED) {
                    enqueue(queueIndex, neighborIndex);
                    colorArray[neighborIndex] = (colorArray[vertexIndex] == BLUE) ? RED : BLUE;
                }
                if (colorArray[neighborIndex] == colorArray[vertexIndex]) return false;
            }
        }
    }
    return true;
}
