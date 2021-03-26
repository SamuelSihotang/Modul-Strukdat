#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
  
//buat struct nya
struct Node{ 
  int data; 
  struct Node *next; 
}; 
  
void input(struct Node **head, int array){ 
    //*booking memori
    struct Node* array_new = (struct Node*) malloc(sizeof(struct Node)); 
  
    //struct last buat ngeloop nyari nilai next = NULL 
    struct Node *last = *head;
  
    //** Taro data array nye
    array_new->data  = array; 
  
    //*** next dibikin NULL karena setiap masok data, node trahir kudu 0
    array_new->next = NULL; 
  
    //****buat masuk data pertama doang, kalo head nya NULL
    if (*head == NULL){ 
       *head = array_new; 
       return; 
    } 
  
    //*****cari next sampe NULL boi
    while (last->next != NULL){
        last = last->next;
    } 
    
    //******Kalo dah nyampe, ubah si next nya ke yg baru boi
    last->next = array_new; 
    return; 
} 

void forEachElement(struct Node *multiply){
    //kalo next nya belum ketemu nol, data nya kaliin aje
    while(multiply != NULL){
        printf("%d ", (multiply->data) * 2);
        multiply = multiply->next;
    }
}

void print(struct Node *node) { 
  //kalo belum ketemu nol di next, print
  while(node != NULL){ 
     printf("%d ", node->data); 
     node = node->next; 
  } 
} 

void reverse(struct Node **head){
    struct Node *temp = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL) {
        // jadikan next sebagai nilai dari next sekarang
        next = current->next;
 
        // asalnya 3 -> 4 -> 5 -> 6
        //jadi 3 <- 4 -> 5 -> 6
        current->next = temp;
 
        // Move pointers one position ahead.
        temp = current;
        current = next;
    }
    *head = temp;
}

int main(){
    struct Node *head = NULL; 
    int arr[5] = {1,2,3,4,5};
    int length = sizeof(arr) / sizeof(int);
  
    for(int i = 0; i < length; ++i){
        input(&head, arr[i]);
    }
    printf("Perkalian: ");
    forEachElement(head);

    printf("\n");
    reverse(&head);
    printf("Reverse: ");
    print(head);
   
    
} 