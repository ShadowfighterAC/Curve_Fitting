#include<iostream>
#include<cctype>
#include<vector>
#include<cmath>
using namespace std;

class input{

    private:

    vector<double> X , Y;
    int n = 0;

    
    protected:

    double sum_X = 0;
    double sum_Y = 0;
    double sum_XY = 0;
    double sum_X_squared = 0;
       
    void Basic_Sums(){

        sum_X = sum_Y = sum_XY = sum_X_squared = 0;

        for(int i = 0 ; i < n ; i++){


            sum_X += X[i];
            sum_Y += Y[i];
            sum_XY += (X[i]*Y[i]);
            sum_X_squared += (X[i]*X[i]);

        }

    }

    double getX(int j){
        return X[j];
    }

    double getY(int k){
        return Y[k];
    }

    int GETn(){
        return n;
    }

    public:

    input(){

        double x_input = 0;
        double y_input = 0;

        cout<<"Enter number of sample points : ";
        cin>>n;

        X.resize(n);
        Y.resize(n);


        cout<<"Enter x and y points : "<<endl;

        for(int i = 0 ; i < n ; i++){
            

            cout<<"Enter point "<<i+1<<" : ";
            cin>>x_input>>y_input;

            X[i] = x_input;
            Y[i] = y_input;

        }

        Basic_Sums();
    }

};

class Determinant{
    public:

    static double Determinant_3x3(double a11,double a12,double a13,
                double a21,double a22,double a23,
                double a31,double a32,double a33)
    {
        return a11*(a22*a33 - a23*a32)
             - a12*(a21*a33 - a23*a31)
             + a13*(a21*a32 - a22*a31);
    }
    
};

class Linear_Fit : public input{

    double a = 0;
    double b = 0;

    public: 

    void fit_Line(){

        int n = GETn();

        b = ((n*sum_XY) - ((sum_X)*(sum_Y)))/((n*sum_X_squared) - ((sum_X)*(sum_X)));

        a = (sum_Y - (b*sum_X))/n;

        cout<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"LSS Equations are : "<<endl;
        cout<<sum_Y<<" = "<<n<<"a + "<<sum_X<<"b"<<endl;
        cout<<sum_XY<<" = "<<sum_X<<"a + "<<sum_X_squared<<"b"<<endl;
        cout<<endl;
        cout<<"---------------------------------------------------------"<<endl;

        cout<<endl;
        cout<<"Where a and b are : "<<endl;
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
        cout<<endl;
        cout<<"---------------------------------------------------------"<<endl;

        cout<<endl;
        cout<<"The best fit line is : "<<"y = "<<a<<" + "<<b<<"x"<<endl;
        cout<<endl;
        cout<<"---------------------------------------------------------"<<endl;


    }

};

class Quadratic_Fit : public input{

    private:

    double a = 0;
    double b = 0;
    double c = 0;

    double sum_X_cubed = 0;
    double sum_X_power_four = 0;
    double sum_X_squaredY = 0;

    public:

    void Quadratic_Sums(){

        sum_X_cubed = sum_X_power_four = sum_X_squaredY = 0;

        int n = GETn();

        for(int l = 0 ; l < n ; l++){

            double Quadratic_X = getX(l);
            double Quadratic_Y = getY(l);


            sum_X_cubed += (Quadratic_X*Quadratic_X*Quadratic_X);
            sum_X_power_four += (Quadratic_X*Quadratic_X*Quadratic_X*Quadratic_X);
            sum_X_squaredY += (Quadratic_X*Quadratic_X*Quadratic_Y);

        }

        
    }
    void fit_Quadratic(){

        Quadratic_Sums();

        int n = GETn();

        double Sx   = sum_X;
        double Sy   = sum_Y;
        double Sx2  = sum_X_squared;
        double Sx3  = sum_X_cubed;
        double Sx4  = sum_X_power_four;
        double Sxy  = sum_XY;
        double Sx2y = sum_X_squaredY;

        double D = Determinant::Determinant_3x3(Sx2, Sx,  n,
                                   Sx3, Sx2, Sx,
                                   Sx4, Sx3, Sx2);
                                   
        if(D == 0){
            cout<<"Quadratic Fit not possible (Determinant = 0)"<<endl;
            return;
        }
        
         
        double Da = Determinant::Determinant_3x3(Sy, Sx,  n,
                                   Sxy, Sx2, Sx,
                                   Sx2y, Sx3, Sx2);  
        

        double Db = Determinant::Determinant_3x3(Sx2, Sy,  n,
                                   Sx3, Sxy, Sx,
                                   Sx4, Sx2y, Sx2);


        double Dc = Determinant::Determinant_3x3(Sx2, Sx,  Sy,
                                   Sx3, Sx2, Sxy,
                                   Sx4, Sx3, Sx2y);  
                                      
    a = Da / D;
    b = Db / D;
    c = Dc / D;

    cout<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"LSS Equations are : "<<endl;
    cout<<sum_Y<<" = "<<sum_X_squared<<"a + "<<sum_X<<"b + "<<n<<"c"<<endl;
    cout<<sum_XY<<" = "<<sum_X_cubed<<"a + "<<sum_X_squared<<"b + "<<sum_X<<"c"<<endl;
    cout<<sum_X_squaredY<<" = "<<sum_X_power_four<<"a + "<<sum_X_cubed<<"b + "<<sum_X_squared<<"c"<<endl;
    cout<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    cout<<endl;
    cout<<"Where a , b and c are : "<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
    cout<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    cout<<endl;
    cout<<"The best fit Quadratic curve is : "<<"y = "<<a<<"x^2 + "<<b<<"x + "<<c<<endl;
    cout<<endl;
    cout<<"---------------------------------------------------------"<<endl;


    }
};

class Exponential_Fit : public input{

    private:

    double A = 0;
    double B = 0;

    double sum_log_Y = 0;
    double sum_X_logY = 0;

    public:

    void Exponential_Sums(){

        sum_log_Y = sum_X_logY = 0;

        int n = GETn();

        for(int m = 0 ; m < n ; m++){

            double Exponential_X = getX(m);
            double Exponential_Y = getY(m);

            if(Exponential_Y <= 0){
                cout<<"Exponential Fit is not possible (y < 0)"<<endl;
                return;
            }

            sum_log_Y += log(Exponential_Y);
            sum_X_logY += (Exponential_X*log(Exponential_Y));

        }

    }


    void fit_Exponential(){

        Exponential_Sums();

        int n = GETn();

        double log_B = ((n*sum_X_logY)-(sum_X)*(sum_log_Y)) / ((n*sum_X_squared)-((sum_X*sum_X)));
        double log_A = ((sum_log_Y)-(log_B*sum_X)) / n ;

        A = exp(log_A);
        B = exp(log_B);


        cout<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"The coefficents of the Exponential Curve are : "<<endl;
        cout<<"a = "<<A<<endl;
        cout<<"b = "<<B<<endl;
        cout<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"The best fit Exponential curve is : "<<"y = "<<A<<" ("<<B<<")^x"<<endl;
        cout<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        
    }


};

int main(int argc, char const *argv[])
{

    char choice;

    cout<<endl;
    cout<<"A. Linear (y = a + bx)"<<endl;
    cout<<"B. Quadratic (y = ax^2 + bx + c)"<<endl;
    cout<<"C. Exponential(y = ab^x)"<<endl;
    cout<<"D. Power (y = ax^b)"<<endl;
    cout<<endl;

    cout<<"Choose The curve to fit : ";
    cin>>choice;
    choice = toupper(choice);


    switch (choice)
    {
    case 'A':
    {
        Linear_Fit Line;
        Line.fit_Line();
        break;
    }

    case 'B':
    {
        Quadratic_Fit Parabola;
        Parabola.fit_Quadratic();
        break;
    }

    case 'C':
    {
        Exponential_Fit Exponential;
        Exponential.fit_Exponential();
        break;
    }

    default:
        cout<<"Enter from given choices";
        break;
    }

    return 0;
}



