#include "Review.h"

/**DEEP COPY**/
List::List(List &copy) {
	Node *pCur = copy.pHead;
	Node *pMem = nullptr;
	while (pCur != nullptr) {
		pMem = new Node(*pCur);
		//check head of list
		//if yes
		//	pHead = pMem;
		//	pHead = pMem;
		// else
		//	pTail ->getNext() = pMem;
		//	pTail = pMem;
		//	pCurr = pCurr->getNext();
	}
}