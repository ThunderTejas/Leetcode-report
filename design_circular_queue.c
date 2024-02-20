typedef struct 
{
    int front;
	int rear;
	int *a;
	int n;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue* q = malloc(sizeof *q);
    q->a =(int*) malloc(sizeof(int) * k);
    q->front =-1;
    q->rear = -1;
    q->n = k;
    return q;
    
}

bool myCircularQueueEnQueue(MyCircularQueue* q, int value)
{
    if((q->rear + 1) % q->n == q->front)
		return false;
	else
	{
	if (q->front == -1) 
		q->front = 0;
	q->rear=(q->rear+1)%q->n;
	q->a[q->rear]=value;
    return true;
	}
  
}

bool myCircularQueueDeQueue(MyCircularQueue* q)
{
    if(q->front==-1)
		return false;
	else
	{

	if (q->front == q->rear) 
	{
      q->front = -1;
      q->rear = -1;
    }
    else
      q->front = (q->front + 1) % q->n;
        return true;
	}
  
}

int myCircularQueueFront(MyCircularQueue* q)
{
    if(q->front==-1)
		return -1;
    return q->a[q->front];
  
}

int myCircularQueueRear(MyCircularQueue* q) 
{
    if(q->front==-1)
		return -1;
   
        return (q->a[q->rear]);
          
}

bool myCircularQueueIsEmpty(MyCircularQueue* q)
{
    if(q->front==-1)
		return true;
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* q) 
{
    if((q->rear + 1) % q->n == q->front)
		return true;
  return false;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj);
}
