package netgloo.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;


@Entity
@Table(name = "at_person")
public class AtPerson{

  // ------------------------
  // PRIVATE FIELDS
  // ------------------------
  
  @Id
  private String id;
  
  // The book's name
  @NotNull
  private String name;
  
  
  // The book's name
  @NotNull
  private String at_person;
  
  //The book's num
  @NotNull
  private int value;
  
 
  // ------------------------
  // PUBLIC METHODS
  // ------------------------
  
  public AtPerson() { }
  
  public AtPerson(String name,String at_person, int value){
    this.name = name;
    this.at_person = at_person;
    this.value = value;
    
  }

  // Getter and setter methods

  public String getName(){
    return name;
  }

  public void setName(String value) {
    this.name = value;
  }

  public String getAt_person() {
    return at_person;
  }
  
  public void setAt_person(String value) {
    this.at_person = value;
  }
  
  public int getValue() {
    return value;
  }

  public void setValue(int value) {
    this.value = value;
  }
  
  
} // class User
