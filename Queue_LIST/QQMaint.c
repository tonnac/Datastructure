#include "QList.h"


int main()
{
	struct Q_List pp;

	QInit(&pp);

	QEmpty(&pp);

	QPush(&pp, 3);QPush(&pp, 5);
	QPush(&pp, 6);QPush(&pp, 7);
	QPush(&pp, 8);QPush(&pp, 9);
	QPush(&pp, 10);QPush(&pp, 11);

	QPop(&pp);QPop(&pp);
	QPop(&pp);QPop(&pp);
	QPop(&pp);QPop(&pp);
	QPop(&pp);QPop(&pp);
	QPop(&pp);



	return 0;
}