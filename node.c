#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>

void *NodeThreadFunc(void *arg);
int StartNode(int arg);

int main(int argc, char *argv[])
{
  int nodeNum;
  if (argc < 2) {
    printf("\n%s:%d", __FUNC__, __LINE__);
    exit(1);
  }
  nodeNum = atoi(argv[1]);
  StartNode(nodeNum);
  return 0;
}

/* Sepaton:
   epoll and connect/reconnect abstract - 
   - tcp/ip
   - RDMA (infiniband)
*/
int StartNode(int arg)
{
  int status;
  pthread_t nodeThread;
  pthread_attr_t nodeThreadAttr;

  status = pthread_create(&nodeThread, &nodeThreadAttr,
			  NodeThreadFunc, (void *)&arg);
  if (status != 0) {
    perror("\nfailed:pthread_create");
    return (status);
  }
}

void *NodeThreadFunc(void *arg1)
{
  int arg = *(int *)arg1;
  int status;
  
  printf("\n%s:%d", __FUNC__, __LINE__);

  status = socket(PF_INET, SOCK_STREAM, 0);
  if (status == -1) {
    perror("\nfaied: socket");
    return ((void *)&status);
  }

  /* open a listen socket */
  /* wait for incoming nodes to connect */
  /* if connection received - resolve order fot tie-break */
  /* perform heartbeats */
  /* If connection is lost, reconnect */
  /* Its not about the code - this can be done as a math at first 
   * on paper for estimateion and scoping
   */
  
  for (;;) {
  }
  return (NULL);
}
