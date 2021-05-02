#include "list.h"


List *
new_list(void)
{
	return calloc(sizeof(List), sizeof(List));
}

List *
append_list(List **list, void *data)
{
	List *head = (*list);
	List *ret = (*list);
	List *new_l = NULL;

	if (head == NULL)
		return NULL;
	if (head->data == NULL) {
		head->data = data;
		return head;
	}

	new_l = new_list();
	if (new_l) {
		new_l->data = data;
		if (head->next == NULL) {
			head->next = new_l;
			return head;
		}
		while (head->next != NULL)
			head = head->next;
		head->next = new_l;
	}
	return ret;
}

List *
insert_list(List **list, void *data, size_t at)
{
	List *head = (*list);
	List *ret = (*list);
	List *new_l = NULL;
	List *tmp = NULL;

	if (head == NULL)
		return NULL;
	if (head->data == NULL) {
		head->data = data;
		return head;
	}

	new_l = new_list();
	if (new_l) {
		new_l->data = data;
		if (at < 1) {
			new_l->next = head;
			ret = new_l;
		} else {
			while (head->next != NULL) {
				if (at <= 2)
					break;
				head = head->next;
				at--;
			}
			if (head->next != NULL)
				tmp = head->next;
			head->next = new_l;
			new_l->next = tmp;
		}
	}
	return ret;
}

void delete_last_list(List **list)
{
	List *head = *list;
	List *tmp = *list;

	if (head != NULL) {
		if (head->next != NULL) {
			while (head->next->next != NULL)
				head = head->next;
			free(head->next);
			head->next = NULL;
		} else {
			free(head);
			head = NULL;
			tmp = NULL;
		}
		(*list) = tmp;
	}
}

void delete_at_list(List **list, size_t at)
{
	List *head = *list;
	List *next_n = head->next;
	List *last = NULL;

	if (head != NULL) {
		if (head->next != NULL) {
			if (at < 1) {
				free(head);
				(*list) = next_n;
			} else {
				while (head->next->next != NULL) {
					if (at <= 2)
						break;
					head = head->next;
					at--;
				}
				next_n = head->next;
				last = next_n->next;
				free(next_n);
				head->next = last;
			}
		} else {
			free(head);
			(*list) = NULL;
		}
	}

}

size_t
get_size_list(List **list)
{
	size_t num = 0;
	List *tmp = *list;
	while (tmp != NULL) {
		tmp = tmp->next;
		num++;
	}
	return num;
}


void
clear_list(List **list)
{
	List *tmp = *list;
	List *next = NULL;
	while (tmp != NULL) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

