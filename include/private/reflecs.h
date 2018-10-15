#ifndef REFLECS_PRIVATE_H
#define REFLECS_PRIVATE_H

#include "types.h"

/* -- Entity API -- */

EcsHandle ecs_new_w_family(
    EcsWorld *world,
    EcsFamily family_id);


/* -- World API -- */

EcsHandle ecs_world_new_handle(
    EcsWorld *world);

EcsFamily ecs_world_register_family(
    EcsWorld *world,
    EcsHandle to_add,
    EcsArray *set);

EcsTable* ecs_world_get_table(
    EcsWorld *world,
    EcsFamily family_id);

void ecs_world_activate_system(
    EcsWorld *world,
    EcsHandle system,
    bool active);

/* -- Family utility API -- */

EcsFamily ecs_family_from_handle(
    EcsWorld *world,
    EcsHandle entity);

EcsFamily ecs_family_merge(
    EcsWorld *world,
    EcsFamily cur_id,
    EcsFamily to_add_id,
    EcsFamily to_remove_id);

bool ecs_family_contains(
    EcsWorld *world,
    EcsFamily family_id_1,
    EcsFamily family_id_2);

/* -- Table API -- */

EcsResult ecs_table_init(
    EcsWorld *world,
    EcsTable *table);

EcsResult ecs_table_init_w_size(
    EcsWorld *world,
    EcsTable *table,
    EcsArray *family,
    uint32_t size);

uint32_t ecs_table_insert(
    EcsTable *table,
    EcsHandle entity);

void ecs_table_delete(
    EcsTable *table,
    uint32_t index);

void *ecs_table_get(
    EcsTable *table,
    uint32_t index);

uint32_t ecs_table_column_offset(
    EcsTable *table,
    EcsHandle component);

bool ecs_table_has_components(
    EcsTable *table,
    EcsArray *components);


/* -- System API -- */

EcsResult ecs_system_notify_create_table(
    EcsWorld *world,
    EcsHandle system,
    EcsTable *table);

void ecs_system_activate_table(
    EcsWorld *world,
    EcsHandle system,
    EcsTable *table,
    bool active);

void ecs_run_job(
    EcsWorld *world,
    EcsJob *job);

void ecs_system_notify(
    EcsWorld *world,
    EcsHandle system,
    EcsSystem *system_data,
    EcsTable *table,
    uint32_t table_index,
    uint32_t row_index);

/* -- Worker API -- */

void ecs_schedule_jobs(
    EcsWorld *world,
    EcsHandle system);

void ecs_prepare_jobs(
    EcsWorld *world,
    EcsHandle system);

void ecs_run_jobs(
    EcsWorld *world);

/* -- Private utilities -- */

void ecs_hash(
    const void *key,
    size_t length,
    uint32_t *result);

EcsRow ecs_to_row(
    uint64_t value);

uint64_t ecs_from_row(
    EcsRow row);

#endif
