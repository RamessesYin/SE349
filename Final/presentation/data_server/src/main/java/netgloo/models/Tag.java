package netgloo.models;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;


@Entity
@Table(name = "tag")
public class Tag{

  // ------------------------
  // PRIVATE FIELDS
  // ------------------------
  
	@NotNull
  private String tag;
  
  // The book's name
  @NotNull
  private String recom_tag;
  
  
  // The book's name
  @Id
  private String name;
  
  
 
  // ------------------------
  // PUBLIC METHODS
  // ------------------------
  
  public Tag() { }
  
  public Tag(String recom_tag,String name){
    this.name = name;
    this.recom_tag = recom_tag;
    
  }

  // Getter and setter methods
  public String getTag(){
	    return tag;
	  }

  public void setTag(String value) {
	    this.tag = value;
	}

  public String getName(){
    return name;
  }

  public void setName(String value) {
    this.name = value;
  }

  public String getRecom_tag() {
    return recom_tag;
  }
  
  public void setRecom_tag(String value) {
    this.recom_tag = value;
  }
  
  
  
} // class User
