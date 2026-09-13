#include <stdio.h>
#include "biocade.h"

void bio_tick(Patient *p) {
    p->tick_count++;

    update_renal(p);
    update_respiratory(p);
    update_cardiovascular(p);
    update_biochemical(p);
    update_immune(p);

    check_vitals(p);
}

int main(void) {
    Patient patient = {
        .tick_count = 0,
        .status = SEVERITY_STABLE,
        .is_alive = true,
        .cv = {
            .heart_rate = 75.0,
            .systolic_bp = 120.0,
            .diastolic_bp = 80.0,
            .stroke_volume = 70.0,
            .mean_arterial_press = 93.3,
            .cardiac_output = 5.25
        },
        .resp = {
            .resp_rate = 14.0,
            .tidal_volume = 500.0,
            .partial_press_o2 = 95.0,
            .partial_press_co2 = 40.0,
            .spo2_percent = 98.0
        },
        .biochem = {
            .blood_ph = 7.40,
            .serum_glucose = 90.0,
            .lactate_level = 1.0,
            .glycosuria_active = false
        },
        .renal = {
            .glomerular_filtration_rate = 100.0,
            .urine_output_rate = 50.0,
            .renin_level = 1.0,
            .angiotensin_ii_level = 1.0,
            .aldosterone_level = 1.0,
            .raas_active = false
        },
        .immune = {
            .pathogen_load = 0,
            .memory_cells_present = 1,
            .lag_cycles_remaining = 3,
            .antibody_titer = 0.0
        }
    };

    printf("=========================================\n");
    printf("   BioCascade Simulation Engine Active   \n");
    printf("=========================================\n");

    for (int cycle = 1; cycle <= 5; cycle++) {
        if (!patient.is_alive) {
            printf("\n[ALERT] Patient expired at tick %lu\n", patient.tick_count);
            break;
        }

        bio_tick(&patient);

        printf("Tick %lu | HR: %.1f bpm | MAP: %.1f mmHg | SpO2: %.1f%% | Urine: %.1f mL/hr\n",
               patient.tick_count,
               patient.cv.heart_rate,
               patient.cv.mean_arterial_press,
               patient.resp.spo2_percent,
               patient.renal.urine_output_rate);
    }

    return 0;
}