# C Language Projects

A collection of C programs I built to practise core C concepts and embedded-style programming.

## Projects

| # | Project | File | What it shows |
|---|---------|------|---------------|
| 1 | Embedded Sensor Manager | `ESM.c` | Unions, structs, enums, memory-efficient design |
| 2 | Calculator | `Calculator.c` | [e.g. functions, switch-case, user input, operators: edit to match the code] |

---

## 1. Embedded Sensor Manager (`ESM.c`)

Manages multiple sensor types (temperature, humidity, pressure) for a memory-constrained embedded device, such as an IoT environmental monitor.

**How it works**
- An **enum** tags the sensor type.
- A **union** stores type-specific data, so all sensor types share one block of memory (the size of the largest member, not the sum).
- A **struct** combines the type tag and the union into one sensor object.
- Functions **configure** a sensor, **read** its data, and **process** the reading with logic specific to the sensor type, using a `switch` on the enum.

**Why a union?** On a microcontroller with very little RAM, sharing memory between sensor types keeps the footprint small. The type tag tells the program which union member is valid, so it never reads the wrong one.

**Concepts:** enums, structs, unions, tagged unions, `switch`, memory efficiency.

## 2. Calculator (`Calculator.c`)

**Features**
- [e.g. addition, subtraction, multiplication, division]
- [e.g. menu-driven loop / handles divide by zero / supports more operations]

**Concepts:** [e.g. functions, `switch-case`, loops, input/output with `scanf` and `printf`]

**Error handling**
- Division by zero: [shows an error message instead of crashing]
- Invalid operator: [rejects anything outside the supported operations]
- Invalid input: [non-numeric input is detected and the user is asked again]
- Modulo by zero / overflow / negative square root: [only if handled]
- Program flow: [keeps running after an error instead of exiting]

## Limitations and next steps
- The sensor manager uses [simulated / manually entered] readings, not real hardware. Next step: port it to an ESP32 or Arduino and read real sensors.
- [Add one improvement idea for the calculator, such as better input validation.]
