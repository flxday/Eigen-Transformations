			Eigen-Transformations

This repository sets forth an example of how to perform the eigen transforms

We have a well located vehicle at the point pO= [POx Poy] T and oriented an angle θ with respect to the origin of the trajectory. This vehicle has a sensor mounted at the known position m B = [m Bx m By ] and oriented an angle β with respect to the base frame of the vehicle. Finally this sensor has detected a point of interest at q S = [q Sx q Sy ].























The rotation matrixes involved are:



and the homogeneous matrixes representing the transformations from the origin to the
base, and from the base to the sensor, are respectively:



So the point q with respect to the vehicle base frame and with respect to the origin of the trajectory is:

