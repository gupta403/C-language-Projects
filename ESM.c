/*Problem Statement
Design a C program for an embedded system that manages multiple sensor types in a smart device (e.g., IoT environmental monitor). Use unions, structs, and enums
to efficiently handle different sensor types (Temperature, Humidity, Pressure) with type-specific configurations and data processing. The program should run on
a constrained embedded system with limited memory, emphasizing efficient use of unions for sensor data storage, and include functions to configure sensors, read
0data, and process readings based on sensor-specific logic.
*/
#include<stdio.h>
enum sensor_type {
    Temperature,Humidity, Pressure
};
union sensor_data{
    struct {
        short int min_range;
        short int max_range;
        float reading;
    }Temperature;
    struct {
        float calibration;
        float reading;

    }Humidity;
    struct {
        short int altitude;
        float reading;

    }Pressure;
};
enum sensor_status{
    Active,Inactive,Error
};

struct sensor {
    unsigned char id;
    char name[20];
    enum sensor_type type;
    union sensor_data data;
    enum sensor_status status; 


};
int main(){
    struct sensor sensor_list[2] = {0};//array of sensors data sensor_list[sensor_count]
    //struct sensor sensor_list[sensor_count] = {0};// temprary variable to save the data of the sensor
    unsigned int init_sensor = 0;
    unsigned int sensor_count = 0;
    while (1){
        if(sensor_count >= 2){
            printf("no slots to add more sensors\n");
            break;
        }
        init_sensor = 0;
        //scanf("%*c");
        printf("Want to add sensor ? enter 1 to add , 0  to skip\n ");
        scanf("%u",&init_sensor);
        //scanf("%*c");
        if(init_sensor == 0){
            break;
        }
        printf("ID: \n");
        scanf("%hhu",&sensor_list[sensor_count].id);
        scanf("%*c");
        printf("Name: \n");
        scanf("%s",&sensor_list[sensor_count].name);
        scanf("%*c");
        printf("Type:(T,H,P) \n");
        char type;
        scanf("%c",&type);
        scanf("%*c");
        switch(type){
            case 'T': sensor_list[sensor_count].type = Temperature;
            break;
            case 'H': sensor_list[sensor_count].type = Humidity;
            break;
            case 'P': sensor_list[sensor_count].type = Pressure;
            break;
           default:
           printf("Please choose as per the options : \n");
           //continue;
        }
        sensor_list[sensor_count].status = Inactive;
        switch(sensor_list[sensor_count].type){
            case Temperature: 
             printf("min: \n");
             scanf("%hd",&sensor_list[sensor_count].data.Temperature.min_range);//here i accessing the sensor_list[sensor_count] value to data that is union and in that we have struct temprature that we added the values from user.
             scanf("%*c");
             printf("max: \n");
             scanf("%hd",&sensor_list[sensor_count].data.Temperature.max_range);
             scanf("%*c");
             printf("Reading: \n");
             scanf("%f",&sensor_list[sensor_count].data.Temperature.reading);
             scanf("%*c");
            
            break;
             // for the humidity data 
            case Humidity:
             printf("Calibration : \n");
             scanf("%f",&sensor_list[sensor_count].data.Humidity.calibration);
             scanf("%*c");
             printf("Reading: \n");
             scanf("%f",&sensor_list[sensor_count].data.Humidity.reading);
             scanf("%*c");
            break;
            //for Pressure data
            case Pressure:
             printf("Altitude : \n");
             scanf("%hd",&sensor_list[sensor_count].data.Pressure.altitude);
             scanf("%*c");
             printf("Reading: \n");
             scanf("%f",&sensor_list[sensor_count].data.Pressure.reading);
             scanf("%*c");
            break;
        }
        sensor_count++;
        sensor_list[sensor_count].status = Active;

    }
    for(int i = 0; i<sensor_count;i++){
        printf("Printing sensor data for Sensors %d\n",i);
        printf("ID: %u\n",sensor_list[i].id);
        printf("Name: %s\n",sensor_list[i].name);
        printf("Type: %u\n",sensor_list[i].type);
    //printf("")
    switch(sensor_list[i].type){
        case Temperature: 
        printf("min:%hd\n",sensor_list[i].data.Temperature.min_range);
        printf("max: %hd\n",sensor_list[i].data.Temperature.max_range);
        printf("Reading: %f\n",sensor_list[i].data.Temperature.reading);
        break;
        // for the humidity data 
        case Humidity:
        printf("Calibration :%f\n",sensor_list[i].data.Humidity.calibration);
        printf("Reading:%f\n",sensor_list[i].data.Humidity.reading);
        break;
        case Pressure:
        printf("Altitude : %hd\n",sensor_list[i].data.Pressure.altitude);
        printf("Reading: %f\n",sensor_list[i].data.Pressure.reading);
        break;
    }
}

    return 0;

};

