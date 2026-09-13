#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef enum {
    SEVERITY_STABLE = 0,
    SEVERITY_WARNING,
    SEVERITY_CRITICAL,
    SEVERITY_FATAL
} PatientStatus;

typedef struct {
    double heart_rate;
    double systolic_bp;
    double diastolic_bp;
    double stroke_volume;
    double mean_arterial_press;
    double cardiac_output;
} CardiovascularSystem;

typedef struct {
    double resp_rate;
    double tidal_volume;
    double partial_press_o2;
    double partial_press_co2;
    double spo2_percent;
} RespiratorySystem;

typedef struct {
    double blood_ph;
    double serum_glucose;
    double lactate_level;
    bool glycosuria_active;
} BiochemicalProfile;

typedef struct {
    double glomerular_filtration_rate;
    double urine_output_rate;
    double renin_level;
    double angiotensin_ii_level;
    double aldosterone_level;
    bool raas_active;
} RenalSystem;

typedef struct {
    int pathogen_load;
    int memory_cells_present;
    int lag_cycles_remaining;
    double antibody_titer;
} ImmuneSystem;

typedef struct {
    unsigned long tick_count;
    PatientStatus status;
    bool is_alive;
    
    CardiovascularSystem cv;
    RespiratorySystem resp;
    BiochemicalProfile biochem;
    RenalSystem renal;
    ImmuneSystem immune;
} Patient;


// Ihave created all function prototypes for all of us , be very careful of the function name and data type must be Patient not anything else like int or float anything else it must be whats written in biocade.h 
void update_cardiovascular(Patient *p);
void update_respiratory(Patient *p);
void update_biochemical(Patient *p);
void update_renal(Patient *p);
void update_immune(Patient *p);
void check_vitals(Patient *p);