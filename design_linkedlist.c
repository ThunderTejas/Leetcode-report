struct node
{
    int val;
    struct node * next;
};

typedef struct {
    struct node * head;
} MyLinkedList;

static struct node * creatNode(int val)
{
    struct node * newNode = malloc(sizeof(struct node));
    assert(newNode);
    newNode->val = val;
    newNode->next = NULL;
    return(newNode);
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    assert(obj);
    obj->head = NULL;
    return (obj);
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    struct node * current = obj->head;
    if(current == NULL) return -1;
    for(int i = 0; i < index; i++)
    {
        if(current->next != NULL)
        {
            current = current->next;
        }
        else
        {
            return -1;
        }
    }
    return (current->val);
 }

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if(obj->head == NULL)
    {
        obj->head = creatNode(val);
    }
    else
    {
        struct node * temp = obj->head;
        obj->head = creatNode(val);
        obj->head->next = temp;
    }
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct node * current = obj->head;
    if(obj->head == NULL)
    {
        myLinkedListAddAtHead(obj, val);
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = creatNode(val);
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct node * current = obj->head;
    if(index == 0)
    {
        myLinkedListAddAtHead(obj, val);
    }
    else
    {
        if(current != NULL)
        {
            for(int i = 1; i < index; i++)
            {
                if(current->next != NULL)
                {
                    current = current->next;
                }
                else
                {
                    return;
                }
            }
            struct node * temp = current->next;
            current->next = creatNode(val);
            current->next->next = temp;
        }
    }  
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    struct node * current = obj->head;
    struct node * prev = obj->head;
    if(current == NULL) return;
    if(index == 0)
    {
        obj->head = current->next;
        free(current);
    }
    else
    {
        for(int i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
            if(current == NULL) break;
        }
        if(current == NULL) return;
        prev->next = current->next;
        free(current);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    struct node * current = obj->head;
    struct node * deleted;
    if(current == NULL)
    {
        free(obj);
    }
    else if(current->next == NULL)
    {
        free(current);
        free(obj);
    }
    else
    {
        while(current->next != NULL)
        {
            deleted = current;
            current = current->next;
            free(deleted);
        }
        free(current);
        free(obj);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
