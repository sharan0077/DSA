typedef struct Itrtr{
	void *list;
	int position;
	int (*hasNext)(struct Itrtr* it);
	void* (*next)(struct Itrtr* it);
}Iterator;