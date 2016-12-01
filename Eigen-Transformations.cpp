#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/Dense>

int main()
{
//	Vectores
Eigen::Vector3d qb;
Eigen::Vector3d q0; 
Eigen::Vector3d q01; 
Eigen::Vector3d p0;
Eigen::Vector3d mb;
Eigen::Vector3d qs; 
//	Rotaciones
Eigen::Matrix3d rot_BS;
Eigen::Matrix3d rot_0B;
Eigen::Matrix3d rot_0S;
//Transformadas
Eigen::Matrix3d tB_S; 
Eigen::Matrix3d t0_B; 
Eigen::Matrix3d t0_S;

//	Datos conocidos
p0 << 23,30,1; //posicion del coche respecto el origen
mb << 1.5,0.75,1; //posicion de sensor respecto el coche
qs << 12,5,1; // posicion del punto respecto al sensor

//	Grados
double theta = 30;
double beta = 25; 
double theta_rad = M_PI * theta/ 180 ;
double beta_rad = M_PI * beta/ 180 ;

//calculo rotacion
//de B a S
rot_BS << cos(theta_rad),-sin(theta_rad),0,sin(theta_rad),cos(theta_rad),0,0,0,1;
//de 0rigen a B
rot_0B << cos(beta_rad),-sin(beta_rad),0,sin(beta_rad),cos(beta_rad),0,0,0,1;

//Calculo de la transformada
//transformada de B a S coche a sensor
tB_S << rot_0B(0,0),rot_0B(0,1),mb(0),rot_0B(1,0),rot_0B(1,1),mb(1),0,0,1;
//transformada de 0 a B origen a coche
t0_B << rot_BS(0,0),rot_BS(0,1),p0(0),rot_BS(1,0),rot_BS(1,1),p0(1),0,0,1;
// Transformada de origen al sensor
t0_S = t0_B * tB_S;

//posicion de q respecto el coche
qb = tB_S*qs;
//posicion de q respecto origen
q0 = t0_B*qb;
//posicion de q respecto al sensor
q01 = t0_S*qs;

std::cout << "qb: " << std::endl << qb << std::endl;
std::cout << "q0: " << std::endl << q0 << std::endl;
std::cout << "t0_S: " << std::endl << t0_S << std::endl;
std::cout << "q01: " << std::endl << q01 << std::endl;

return 1;
}