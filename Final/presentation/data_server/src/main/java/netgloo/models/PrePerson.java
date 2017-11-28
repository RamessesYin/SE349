package netgloo.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;


@Entity
@Table(name = "pre_person")
public class PrePerson{

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
  private String pre_person;
  

  
 
  // ------------------------
  // PUBLIC METHODS
  // ------------------------
  
  public PrePerson() { }
  
  public PrePerson(String name,String at_person){
    this.name = name;
    this.pre_person = pre_person;
    
  }

  // Getter and setter methods

  public String getName(){
    return name;
  }

  public void setName(String value) {
    this.name = value;
  }

  public String getPre_person() {
    return pre_person;
  }
  
  public void setPre_person(String value) {
    this.pre_person = value;
  }
  
  
  
} // class User
