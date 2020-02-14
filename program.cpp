#include <simplecpp>
#include <cmath>

const double pi = 3.1415;//enable pi to be called as "PI"


class V2 {
	//variables
	public:
	double x;
	double y;
	
	//constructors
	V2(){x=0; y=0;}
	V2(double cordx, double cordy){x=cordx; y=cordy;}
	

	//operator overloading

	//addition operator
		V2 operator+ (V2 vector)
			{V2 res;
			res.x=x+vector.x;
			res.y=y+vector.y;
			return res;
			}

	//subtraction operator
		V2 operator- (V2 vector)
			{V2 res;
			res.x=x-vector.x;
			res.y=y-vector.y;
			return res;
			}

	//assignment operator
		void operator= (V2 vector)
			{x=vector.x;
			y=vector.y;
			}
		
	//multiplication by a scalar
		V2 operator* (double n)
			{V2 res;
			res.x=x*n;
			res.y=y*n;
			return res;
			}
		
	//division by a scalar
	    V2 operator/ (double n)
	    	{V2 res;
	    	res.x=x/n;
	    	res.y=y/n;
	    	return res;
	    	}

 	//member functions
 	
 	//function to determine angle made by vector with the positive x-axis
	double angle()
		{if (x=0) return pi/2;
		else return atan(y/x);}
	
    friend class ptcharge;// allowing access to private variables

};//

class ptcharge {
	public:
		double charge;
		V2 pos;
		

	//member functions

};//end of charge class


	//function to determine the magnitude of vector
	double mod (V2 vector)
		{double tmp;
		tmp=pow(vector.x,2)+pow(vector.y,2);
		return sqrt(tmp);
		}
		

	//function to check if another charge is encountered
	bool check(V2 vector, ptcharge array[],short size)
		{for(int i=0; i<size; i++)
		    {if(mod(array[i].pos-vector)<=4)return true;
		    else if (vector.x>=500||vector.x<=0||vector.y<=0||vector.y>=500)return true;
			}//end of for loop
		return false;
		}
		

	//function to calculate resultant electric field due to given charge configuration
	V2 field(V2 point, ptcharge array[], short size)
		{V2 res;  
		double dist=0, dist3=0;
		
		for(int i=0; i<size; i++)
			{dist=mod(point-array[i].pos);
		    dist3=pow(dist,3);
		    
			res=res+(point-array[i].pos)*((array[i].charge)/dist3);

		} 
		return res;
		}


	//function to print line on screen
	void lineprint (V2 start, V2 end)
		{Line l(start.x, start.y, end.x, end.y);
		l.imprint();
		}


 	//function to drawing the initial porition of line from a point charge
	V2 initline (ptcharge charge, int angle)
		{V2 res;
		V2 advance(5*cosine(angle),5*sine(angle));
		res=charge.pos+advance;

		Line l(charge.pos.x, charge.pos.y,res.x,res.y);
		l.imprint();
		return res;
		}




main_program{
	short num;
	cout<<"Specify number of charges to be placed (<=5):"<<endl;
	cin>>num;
	if (num>5)
		{cout << "Error!! More than 5 charges are demanded... Program is exiting now."; return -1;
		};
	
	initCanvas("fieldlines", 500, 500);
	Text t(40,30,"Field Lines");//labelling canvas

	ptcharge charges[5];//array to store data of charges that user wants
	
	Circle c1(10,10,10);//The circles used to represent the charges have to be declared outside the loops so that their fills can be observed throughout the program
	c1.hide();
	Circle c2(10,10,10);
	c2.hide();
	Circle c3(10,10,10);
	c3.hide();
	Circle c4(10,10,10);
	c4.hide();
	Circle c5(10,10,10);
	c5.hide();

	
	for(int i=0; i<num; i++)
		{cout<<"Give charge of particle:"<<endl;
		cin>>charges[i].charge;

		int click;//temporarily used to store value generated by getClick
		click=getClick();
		charges[i].pos.x=click/65536;
		charges[i].pos.y=click%65536;//2^16=65536
		
		//displaying point charges
		if(i==0)
			{c1.moveTo(charges[i].pos.x,charges[i].pos.y);
                if(charges[i].charge>0)
		    		{
    				c1.setFill(true);
			    	c1.setColor(COLOR("red"));
					}//end of inner if statement

				else if(charges[i].charge<0)
		    		{
					c1.setFill(true);
		    		c1.setColor(COLOR("blue"));
					}//end of else if statement

			c1.show();
			}//end of outer if statement
		
        if(i==1)
			{c2.moveTo(charges[i].pos.x,charges[i].pos.y);
                if(charges[i].charge>0)
		    		{
    				c2.setFill(true);
			    	c2.setColor(COLOR("red"));
					}//end of inner if statement

				else if(charges[i].charge<0)
		    		{
					c2.setFill(true);
		    		c2.setColor(COLOR("blue"));
					}//end of else if statement

			c2.show();
			}//end of outer else if statement
        
        if(i==2)
			{c3.moveTo(charges[i].pos.x,charges[i].pos.y);
                if(charges[i].charge>0)
		    		{
    				c3.setFill(true);
			    	c3.setColor(COLOR("red"));
					}//end of inner if statement

				else if(charges[i].charge<0)
		    		{
					c3.setFill(true);
		    		c3.setColor(COLOR("blue"));
					}//end of else if statement

			c3.show();
			}//end of outer else if statement
        
        if(i==3)
			{c4.moveTo(charges[i].pos.x,charges[i].pos.y);
                if(charges[i].charge>0)
		    		{
    				c4.setFill(true);
			    	c4.setColor(COLOR("red"));
					}//end of inner if statement

				else if(charges[i].charge<0)
		    		{
					c4.setFill(true);
		    		c4.setColor(COLOR("blue"));
					}//end of else if statement

			c4.show();
			}//end of outer else if statement
        
        if(i==4)
			{c5.moveTo(charges[i].pos.x,charges[i].pos.y);
                if(charges[i].charge>0)
		    		{
    				c5.setFill(true);
			    	c5.setColor(COLOR("red"));
					}//end of inner if statement

				else if(charges[i].charge<0)
		    		{
					c5.setFill(true);
		    		c5.setColor(COLOR("blue"));
					}//end of else if statement

			c5.show();
			}//end of outer else if statement
		}//end of for loop
		

 //drawing electric field pattern
	V2 point;
	
	V2 elecfield;
	V2 dir;
	
	for(int j=0; j<num; j++)
	{
		for(int i=0; i<12; i++)
		{
            point=initline(charges[j],30*i);

			while(!check(point, charges, num))
				{
				elecfield=field(point,charges,num);//calculating resultant electric field
		        
				dir=elecfield/(mod(elecfield));
				
				if(charges[j].charge < 0) dir = dir * (-1);
                
				lineprint(point,(point+(dir*5)));//drawing the electric field line
				point=point+dir*5;//advancing the loop
				}

		}//end of inner for loop
		
	}//end of outer for loop
	wait(10);
	
cout<<"FIELD LINESS MAPPED SUCCESFULLY"<<endl;
return 0;
}

