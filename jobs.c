#include <stdlib.h>

#include "jobs.h"

Job new_job(int jid, pid_t pid, char* line) {
    Job result = {
        .job_id = jid,
        .process_id = pid,
        .line = line
    };

    return result;
}

JobListNode* new_job_list_node(Job job) {
    JobListNode* result = (JobListNode*) malloc(sizeof(JobListNode));
    result->job = job;
    result->next = NULL;

    return result;
}

JobList new_job_list() {
    JobList list = {
        .first = NULL,
        .last = NULL
    };

    return list;
}

void add_process_to_job_list(JobList* list, pid_t pid, char* line) {
    int jid;
    if(list->last == NULL) {
        jid = 1;
    } else {
        jid = list->last->job.job_id + 1;
    }

    Job job = new_job(jid, pid, line);
    JobListNode* new_node = new_job_list_node(job);

    if(list->last == NULL) {
        list->first = new_node;
        list->last = new_node;
    } else {
        list->last->next = new_node;
        list->last = new_node;
    }
}

bool get_job_with_pid(JobList* list, pid_t pid, Job* result) {
    JobListNode* ptr = list->first;

    while (ptr != NULL) {
        if(ptr->job.process_id == pid) {
            *result = ptr->job;
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

bool get_job_with_jid(JobList* list, int jid, Job* result) {
    JobListNode* ptr = list->first;

    while (ptr != NULL) {
        if(ptr->job.job_id == jid) {
            *result = ptr->job;
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}

void remove_job_with_pid(JobList* list, pid_t pid) {

}